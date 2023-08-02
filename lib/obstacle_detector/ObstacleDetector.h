#ifndef OBSTACLE_DETECTOR_H
#define OBSTACLE_DETECTOR_H

#include <torch/script.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "Yolo.h"
#include "CameraCapture.h"
#include "GPIOController.h"

class ObstacleDetector {
public:
    ObstacleDetector(const std::string& modelPath, const std::string& classNamesPath);
    void processFrames();

private:
    Yolo yolo;
    GPIOController gpioController;

    // GPIO Pin numbers
    const int pinRight = 17;
    const int pinCenter = 27;
    const int pinLeft = 22;
};

#endif
