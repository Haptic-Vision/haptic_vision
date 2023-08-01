#include "CameraCapture.h"

CameraCapture::CameraCapture() {}

CameraCapture::~CameraCapture()
{
    close();
}

bool CameraCapture::open(int index)
{
    cap.open(index); // Opens the camera
    return isOpened(); // Returns a boolean value according to the output
}

void CameraCapture::close()
{
    if (isOpened())
    {
        cap.release();
    }
}

bool CameraCapture::isOpened() const
{
    return cap.isOpened();
}

bool CameraCapture::read(cv::Mat& frame)
{
    return cap.read(frame);
}

void CameraCapture::setProperty(int propId, double value)
{
    cap.set(propId, value);
}
