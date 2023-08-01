#ifndef PERSON_DETECTOR_H
#define PERSON_DETECTOR_H

#include <torch/script.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "Yolo.h"
#include "CameraCapture.h"


class ObstacleDetector {
public:
    ObstacleDetector(const std::string& modelPath, const std::string& classNamesPath);
    void processFrames();

private:
    Yolo yolo;
};

#endif  // PERSON_DETECTOR_H
