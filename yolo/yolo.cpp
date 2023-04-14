#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <raspicam/raspicam_cv.h>


std::vector<std::string> load_class_list() {
    std::vector<std::string> class_list;
    std::ifstream ifs("classes.txt");
    std::string line;
    while (getline(ifs, line)) {
        class_list.push_back(line);
    }
    return class_list;
}

const std::string YOLO_VERSION = "v4-tiny";

void load_net(cv::dnn::Net &net, bool is_cuda) {
    auto result = cv::dnn::readNetFromDarknet("yolov4-tiny.cfg", "yolov4-tiny.weights");
    if (is_cuda) {
        std::cout << "Attempty to use CUDA\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA_FP16);
    } else {
        std::cout << "Running on CPU\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }
    net = result;
}


double calculate_distance(double real_width_cm, double focal_length_mm, int image_width) {
 /*   // Convert focal length to centimeters
    double focal_length_cm = focal_length_mm / 10.0;
    // Convert real_width to meters
    double real_width_m = real_width_cm / 100.0;
    // Calculate the distance to the object in meters */
    return (real_width_cm * focal_length_mm) / (image_width);
}


const std::vector<cv::Scalar> colors = {cv::Scalar(255, 255, 0),
                                         cv::Scalar(0, 255, 0),
                                         cv::Scalar(0, 255, 255),
                                         cv::Scalar(255, 0, 0)};

int main(int argc, char ** argv)
{
    std::vector<std::string> class_list = load_class_list();

    raspicam::RaspiCam_Cv camera;
    camera.set(cv::CAP_PROP_FORMAT, CV_8UC3);
    camera.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    camera.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    if (!camera.open()) {
        std::cerr << "Error opening camera\n";
        return -1;
    }

    bool is_cuda = argc > 1 && strcmp(argv[1], "cuda") == 0;

    cv::dnn::Net net;
    load_net(net, is_cuda);

    auto model = cv::dnn::DetectionModel(net);
    model.setInputParams(1./255, cv::Size(416, 416), cv::Scalar(), true);

    cv::Mat frame;
    int frame_count = 0;
    double fps = -1;
    int total_frames = 0;
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    while (true) {
        camera.grab();
        camera.retrieve(frame);
        if (frame.empty())
        {
            std::cout << "End of stream\n";
            break;
        }

        std::vector<int> classIds;
        std::vector<float> confidences;
        std::vector<cv::Rect> boxes;

        // Constants for focal length calculation
        const double KNOWN_DISTANCE = 100.0; // cm
        const double KNOWN_WIDTH = 20.0; // cm

        model.detect(frame, classIds, confidences, boxes, .2, .4);
        frame_count++;
        total_frames++;

        // Focal length calculation
        double focal_length = 3.04; //mm

        int detections = classIds.size();

        for (int i = 0; i < detections; ++i) {
            auto box = boxes[i];
            auto classId = classIds[i];
            const auto color = colors[classId % colors.size()];
            cv::rectangle(frame, box, color, 3);
            
            // Distance calculation
            double distance = calculate_distance(KNOWN_WIDTH, focal_length, frame.cols);

            cv::rectangle(frame, cv::Point(box.x, box.y - 20), cv::Point(box.x, box.y), color, -1);
            std::stringstream ss;
            ss << class_list[classId] << " (" << std::fixed << std::setprecision(2) << confidences[i] * 100 << "%)" << " - " << distance << "m";
            std::string label = ss.str();
            int baseline;
            cv::Size labelSize = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseline);
            cv::putText(frame, label, cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1);
            }
        cv::imshow("Object Detection", frame);
        if (cv::waitKey(1) == 'q')
            break;
    }

    double elapsed_time = double(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count());
    fps = double(frame_count) / (elapsed_time / 1000);
    std::cout << "Average FPS: " << std::fixed << std::setprecision(2) << fps << std::endl;
    std::cout << "Total frames: " << total_frames << std::endl;

    camera.release();
    cv::destroyAllWindows();

 return 0;
}
