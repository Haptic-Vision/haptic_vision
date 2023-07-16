#ifndef CAMERA_CAPTURE_H
#define CAMERA_CAPTURE_H

#include <opencv2/opencv.hpp>

class CameraCapture {
public:
    CameraCapture();
    ~CameraCapture();
    bool open(int index);
    void close();
    bool isOpened() const;
    bool read(cv::Mat& frame);
    void setProperty(int propId, double value); // New member function to set properties

private:
    cv::VideoCapture cap;
};

#endif  // CAMERA_CAPTURE_H
