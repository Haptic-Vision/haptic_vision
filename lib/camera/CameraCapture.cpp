#include "CameraCapture.h"

CameraCapture::CameraCapture() {}

//Constructor for CameraCapture class

CameraCapture::~CameraCapture()
{
    close();
}

//Destructor for the CameraCapture class

bool CameraCapture::open(int index)
{
    cap.open(index); //Opens the camera using open() function of CameraCampure class
    return isOpened(); // Returns a boolean value if its successful or not 
}

void CameraCapture::close() //Function Checks if the Picam is open, if so, releases it by calling the release() function of the VideoCapture class.
{
    if (isOpened())
    {
        cap.release(); 
    }
}

bool CameraCapture::isOpened() const //This function checks whether PiCam is open. It uses the isOpened() function of the VideoCapture class
{
    return cap.isOpened(); //returns a boolean value indicating the device's open status.
}

bool CameraCapture::read(cv::Mat& frame) //This function reads the next available frame from the PiCam and stores it in the frame parameter, passed by reference. It uses the read() function of the VideoCapture class to read the frame
{
    return cap.read(frame); //returns a boolean value indicating whether the read operation was successful or not.
}

void CameraCapture::setProperty(int propId, double value) //This function sets a property value of the PiCam specified by the propId parameter. 
    cap.set(propId, value); //uses the set() function of the VideoCapture class to set the property.The propId parameter specifies the property to set, and the value parameter specifies the new value for the property.
}
