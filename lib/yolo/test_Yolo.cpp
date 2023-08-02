#include <gtest/gtest.h>
#include "Yolo.h"

// Test fixture class
class YoloTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // Code here will be called before each test case.
        modelPath = "../yolov5s.torchscript.pt";
        classNamesPath = "../coco.names";
    }

    // Add member variables specific to the test fixture.
    std::string modelPath;
    std::string classNamesPath;
};

// Define test cases using TEST_F macro.
TEST_F(YoloTest, LoadYoloModel) {
    // Test loading YOLO model
    Yolo yolo(modelPath, classNamesPath);
    const std::vector<std::string>& classnames = yolo.getClassNames();
    ASSERT_GT(classnames.size(), 0);
}

TEST_F(YoloTest, DetectObjects) {
    // Test detecting objects using YOLO model
    Yolo yolo(modelPath, classNamesPath);
    cv::Mat inputFrame(384, 640, CV_8UC3, cv::Scalar(0, 0, 0)); // Black frame
    std::vector<torch::Tensor> detections = yolo.detectObjects(inputFrame, 0.4, 0.5);
    ASSERT_EQ(detections.size(), 0); // No objects should be detected in a black frame.
}
