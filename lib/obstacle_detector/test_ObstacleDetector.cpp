/**
 * @file test_ObstacleDetector.cpp
 * @author Joseph Joel
 * @brief Camera unit test.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "gtest/gtest.h"
#include "ObstacleDetector.h"

/**
 * @brief Construct a new TEST object.
 * 
 */
TEST(ObstacleDetectorTest, ProcessFrames) {
    ObstacleDetector detector("../yolov5s.torchscript.pt", "../coco.names");
}
