#ifndef CAMERA_CAPTURE_H
#define CAMERA_CAPTURE_H

#include <opencv2/opencv.hpp>

class CameraCapture {
public:
    CameraCapture(); // Constructor
    ~CameraCapture(); // Destructor
    bool open(int index); // Opens camera with a specific index
    void close(); // Function to close the camera
    bool isOpened() const; // Checks if the camera is open
    bool read(cv::Mat& frame); // To read the next frame from the camera and store
    void setProperty(int propId, double value); // New member function to set properties

private:
    cv::VideoCapture cap; // Instance of cv::VideoCapture class to provide access to the camera
};

#endif  // CAMERA_CAPTURE_H
