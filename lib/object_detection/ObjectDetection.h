#ifndef OBJECT_DETECTION_H
#define OBJECT_DETECTION_H

#include <opencv2/opencv.hpp>

class ObjectDetection {
public:
    ObjectDetection(); // Constructor
    ~ObjectDetection(); // Destructor
    bool loadCascade(const std::string& cascadePath); // Load the Haar cascade XML file
    void detectObjects(cv::Mat& frame); // Perform object detection on the input frame

private:
    cv::CascadeClassifier cascade; // Haar cascade classifier
};

#endif  // OBJECT_DETECTION_H
