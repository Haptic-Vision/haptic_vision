/**
 * @file test_CameraCapture.cpp
 * @author Joseph Joel
 * @brief Camera unit test.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include "CameraCapture.h"

/**
 * @brief Camera open and close test.
 * 
 */
TEST(CameraCaptureTest, OpenCamera) {
    CameraCapture cap;
    EXPECT_TRUE(cap.open(0));
    EXPECT_TRUE(cap.isOpened());
    cap.close();
}

/**
 * @brief Camera read frame test.
 * 
 */
TEST(CameraCaptureTest, ReadFrame) {
    CameraCapture cap;
    EXPECT_TRUE(cap.open(0));
    
    cv::Mat frame;
    EXPECT_TRUE(cap.read(frame));
    EXPECT_FALSE(frame.empty());
    
    cap.close();
}

/**
 * @brief Camera set property test.
 * 
 */
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

/**
 * @brief To run all tests.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
