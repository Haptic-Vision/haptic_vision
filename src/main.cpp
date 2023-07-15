#include <opencv2/opencv.hpp>
#include "CameraCapture.h"

// Function to process each frame captured from the camera
void processFrame(cv::Mat frame)
{
    // Add your image processing logic here
    // Example: Display the frame
    cv::imshow("Camera", frame);
    cv::waitKey(1);  // Adjust the delay as needed
}

// Callback function invoked for each frame captured from the camera
void cameraCallback(const cv::Mat& frame, void* userData)
{
    cv::Mat copyFrame = frame.clone();  // Create a copy of the frame
    processFrame(copyFrame);
}

int main()
{
    CameraCapture capture;

    if (!capture.open(0))
    {
        std::cout << "Failed to open the camera." << std::endl;
        return -1;
    }

    cv::namedWindow("Camera", cv::WINDOW_NORMAL);

    // Set the callback function for capturing frames
    capture.setProperty(cv::CAP_PROP_FRAME_WIDTH, 640);
    capture.setProperty(cv::CAP_PROP_FRAME_HEIGHT, 480);
    capture.setProperty(cv::CAP_PROP_AUTOFOCUS, 0);  // Disable autofocus (if available)
    capture.setProperty(cv::CAP_PROP_AUTO_EXPOSURE, 0.25);  // Set fixed exposure (if available)
    capture.setProperty(cv::CAP_PROP_BUFFERSIZE, 1);  // Set buffer size to 1 to reduce latency
    
    cv::Mat frame;
    while (true)
    {
        if (!capture.read(frame))  // Read a new frame from the camera
        {
            std::cout << "Failed to capture a frame." << std::endl;
            break;
        }

        cameraCallback(frame, nullptr);

        if (cv::waitKey(1) == 27)  // Exit if the 'Esc' key is pressed
            break;
    }

    cv::destroyAllWindows();
    return 0;
}