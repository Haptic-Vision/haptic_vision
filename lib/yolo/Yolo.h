#ifndef YOLO_H
#define YOLO_H

#include <torch/script.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

class Yolo {
public:
    Yolo(const std::string& modelPath, const std::string& classNamesPath);
    std::vector<torch::Tensor> detectObjects(const cv::Mat& inputFrame, float scoreThreshold = 0.5, float iouThreshold = 0.5);
    const std::vector<std::string>& getClassNames() const; // Public member function to access class names

private:
    std::vector<std::string> classnames;
    torch::jit::script::Module module;

    std::vector<torch::Tensor> nonMaxSuppression(torch::Tensor preds, float scoreThreshold, float iouThreshold);
};

#endif  // YOLO_H
