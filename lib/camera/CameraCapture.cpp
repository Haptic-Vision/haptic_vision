/**
 * @file CameraCapture.cpp
 * @author Joseph Joel
 * @brief This files defines all the function needed to run the camera.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "CameraCapture.h"

/**
 * @brief Construct a new Camera Capture:: Camera Capture object.
 * 
 */
CameraCapture::CameraCapture() {}

/**
 * @brief Destroy the Camera Capture:: Camera Capture object.
 * 
 */
CameraCapture::~CameraCapture()
{
    close();
}

/**
 * @brief Function opens the launches the camera and gives feedback of its state.
 * 
 * @param index 
 * @return true 
 * @return false 
 */
bool CameraCapture::open(int index)
{
    cap.open(index); // Opens the camera
    return isOpened(); // Returns a boolean value according to the output
}

/**
 * @brief Function closes the camera.
 * 
 */
void CameraCapture::close()
{
    if (isOpened())
    {
        cap.release();
    }
}

/**
 * @brief Checks if camera is open.
 * 
 * @return true 
 * @return false 
 */
bool CameraCapture::isOpened() const
{
    return cap.isOpened();
}

/**
 * @brief Records data from camera.
 * 
 * @param frame 
 * @return true 
 * @return false 
 */
bool CameraCapture::read(cv::Mat& frame)
{
    return cap.read(frame);
}

/**
 * @brief Used to set camera properties.
 * 
 * @param propId 
 * @param value 
 */
void CameraCapture::setProperty(int propId, double value)
{
    cap.set(propId, value);
}
