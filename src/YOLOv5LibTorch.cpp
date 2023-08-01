#include <iostream>
#include <time.h>
#include "CameraCapture.h"
#include "ObstacleDetector.h"

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