#include "gtest/gtest.h"
#include "ObstacleDetector.h"

TEST(ObstacleDetectorTest, ProcessFrames) {
    ObstacleDetector detector("../yolov5s.torchscript.pt", "../coco.names");
}
