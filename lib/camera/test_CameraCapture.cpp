#include <gtest/gtest.h>
#include "CameraCapture.h"

TEST(CameraCaptureTest, OpenCamera) {
    CameraCapture cap;
    EXPECT_TRUE(cap.open(0));
    EXPECT_TRUE(cap.isOpened());
    cap.close();
}

TEST(CameraCaptureTest, ReadFrame) {
    CameraCapture cap;
    EXPECT_TRUE(cap.open(0));
    
    cv::Mat frame;
    EXPECT_TRUE(cap.read(frame));
    EXPECT_FALSE(frame.empty());
    
    cap.close();
}

TEST(CameraCaptureTest, SetProperty) {
    CameraCapture cap;
    EXPECT_TRUE(cap.open(0));
    
    int width = 640;
    int height = 384;
    cap.setProperty(cv::CAP_PROP_FRAME_WIDTH, width);
    cap.setProperty(cv::CAP_PROP_FRAME_HEIGHT, height);
    
    cv::Mat frame;
    cap.read(frame);
    EXPECT_EQ(frame.cols, width);
    EXPECT_EQ(frame.rows, height);
    
    cap.close();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
