/**
 * @file main.cpp
 * @author Joseph Joel
 * @brief This file is the main code to run the system.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <time.h>
#include "CameraCapture.h"
#include "ObstacleDetector.h"

/**
 * @brief This is the main function to the run the system.
 * 
 * @return int 
 */
int main()
{
    // Loading  Module
    torch::jit::script::Module module = torch::jit::load("../yolov5s.torchscript.pt");

    std::vector<std::string> classnames;
    std::ifstream f("../coco.names");
    std::string name = "";
    while (std::getline(f, name))
    {
        classnames.push_back(name);
    }

    ObstacleDetector obstacleDetector("../yolov5s.torchscript.pt", "../coco.names");
    obstacleDetector.processFrames();

    return 0;
}