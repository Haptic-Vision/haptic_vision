#include "ObstacleDetector.h"

ObstacleDetector::ObstacleDetector(const std::string& modelPath, const std::string& classNamesPath)
    : yolo(modelPath, classNamesPath)
{
}

void ObstacleDetector::processFrames()
{
    CameraCapture cap;
    cap.open(0);
    cap.setProperty(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.setProperty(cv::CAP_PROP_FRAME_HEIGHT, 384);
    cv::Mat frame, img;

    while (cap.isOpened())
    {
        // Start timing for FPS calculation
        clock_t start = clock();

        cap.read(frame);
        if (frame.empty())
        {
            std::cout << "Read frame failed!" << std::endl;
            break;
        }

        // Detect obstacles in the frame
        std::vector<torch::Tensor> obstacleDetections = yolo.detectObjects(frame, 0.4, 0.5);

        // Process obstacle detections
        for (const torch::Tensor& detection : obstacleDetections)
        {
            float left = detection[0][0].item().toFloat() * frame.cols / 640;
            float top = detection[0][1].item().toFloat() * frame.rows / 384;
            float right = detection[0][2].item().toFloat() * frame.cols / 640;
            float bottom = detection[0][3].item().toFloat() * frame.rows / 384;
            float score = detection[0][4].item().toFloat();

            // Calculate the midpoint of the bounding box
            float centerX = (left + right) / 2;
            float centerY = (top + bottom) / 2;

            std::string positionLabel;
            // Determine whether the obstacle is on the left, right, or center of the frame
            if (centerX < frame.cols / 3)
            {
                positionLabel = "Left";
            }
            else if (centerX > frame.cols * 2 / 3)
            {
                positionLabel = "Right";
            }
            else
            {
                positionLabel = "Center";
            }

            std::cout << "Obstacle detected at (" << positionLabel << ") with score: " << score << std::endl;

            cv::rectangle(frame, cv::Rect(left, top, (right - left), (bottom - top)), cv::Scalar(0, 255, 0), 2);
            cv::putText(frame,
                        "Obstacle: " + cv::format("%.2f", score) + " - " + positionLabel,
                        cv::Point(left, top),
                        cv::FONT_HERSHEY_SIMPLEX, (right - left) / 200, cv::Scalar(0, 255, 0), 2);
        }

        // Display the frame
        // cv::putText(frame, "FPS: " + std::to_string(int(1e7 / (clock() - start))),
        //             cv::Point(50, 50),
        //             cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
        // cv::imshow("", frame);
        // if (cv::waitKey(1) == 27)
        //     break;
    }

    cap.close();
}
