/**
 * @file ObstacleDetector.h
 * @author Joseph Jeol
 * @brief The file declares all the headers and functions to detct position of obstacle.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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
    const int pinLeft = 22;
};

#endif
