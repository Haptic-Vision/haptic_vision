#include "CameraCapture.h"

CameraCapture::CameraCapture() {}

//Constructor for the class CameraCapture

CameraCapture::~CameraCapture()
{
    close();
}

//Destructor for the CameraCapture class

bool CameraCapture::open(int index)
{
    cap.open(index); //Opens the camera 
    return isOpened(); // Returns a boolean value according to the output
}

void CameraCapture::close() //Function Checks if the Picam is open, if yes, invokes release() function from VideoCapture class.
{
    if (isOpened())
    {
        cap.release(); 
    }
}

bool CameraCapture::isOpened() const 
{
    return cap.isOpened(); //returns a boolean value shows that if the device is open or not.
}

bool CameraCapture::read(cv::Mat& frame) //function is used here to reads the next available frame from the PiCam and store it in the parameter 'frame',.read() function is used here to read the frame(From VideoCapture class)
{
    return cap.read(frame); //returns a boolean value which shows if it was successful in reading.
}

void CameraCapture::setProperty(int propId, double value){ // Function here sets a property value of the PiCam which is given by the propId parameter. 
    cap.set(propId, value); //To set the property set() function is used from VideoCApture class.propId is a parameter which defines the property to set, and the value parameter defines the new value for the property.
}
