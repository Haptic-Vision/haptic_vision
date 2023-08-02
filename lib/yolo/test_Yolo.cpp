/**
 * @file test_Yolo.cpp
 * @author Joseph Joel
 * @brief Yolo unit test.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include "Yolo.h"

/**
 * @brief Test fixture class.
 * 
 */
class YoloTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        modelPath = "../yolov5s.torchscript.pt";
        classNamesPath = "../coco.names";
    }

    std::string modelPath;
    std::string classNamesPath;
};

/**
 * @brief Construct test 1 object.
 * 
 */
TEST_F(YoloTest, LoadYoloModel) {
    Yolo yolo(modelPath, classNamesPath);
    const std::vector<std::string>& classnames = yolo.getClassNames();
    ASSERT_GT(classnames.size(), 0);
}

/**
 * @brief Construct test 2 object.
 * 
 */
TEST_F(YoloTest, DetectObjects) {
    Yolo yolo(modelPath, classNamesPath);
    cv::Mat inputFrame(384, 640, CV_8UC3, cv::Scalar(0, 0, 0)); // Black frame
    std::vector<torch::Tensor> detections = yolo.detectObjects(inputFrame, 0.4, 0.5);
    ASSERT_EQ(detections.size(), 0);
}
