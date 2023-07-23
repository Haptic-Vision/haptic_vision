#include "ObjectDetection.h"

ObjectDetection::ObjectDetection() {}

ObjectDetection::~ObjectDetection() {}

bool ObjectDetection::loadCascade(const std::string& cascadePath)
{
    return cascade.load(cascadePath); // Load the Haar cascade XML file
}

void ObjectDetection::detectObjects(cv::Mat& frame)
{
    if (cascade.empty())
    {
        std::cout << "Haar cascade not loaded!" << std::endl;
        return;
    }

    std::vector<cv::Rect> objects;
    cascade.detectMultiScale(frame, objects, 1.1, 3, 0, cv::Size(30, 30));

    // Draw rectangles around the detected objects
    for (const auto& objRect : objects)
    {
        cv::rectangle(frame, objRect, cv::Scalar(255, 0, 0), 2);
    }

    cv::imshow("Object Detection", frame);
    cv::waitKey(1);
}
