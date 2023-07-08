# HapticVision (aka "HViz")
A device that helps perceive your surrounding by using the sense of touch. 

<img src="https://github.com/Haptic-Vision/haptic_vision/blob/main/Documentation/pulsating.gif" width="230" height="400">

## The Team
- [@rdj2829](https://github.com/rdj2829)
- [@dheerajsankar](https://github.com/dheerajsankar)
- [@kprakz](https://github.com/kprakz)
- [@josephjoel3099](https://github.com/josephjoel3099)

## Socials
- [Instagram](https://www.instagram.com/hapticvision_/)

## Repos
- [Documentation](https://github.com/Haptic-Vision/Documentation)
- [Socials](https://github.com/Haptic-Vision/Socials)
- [Housekeeping](https://github.com/Haptic-Vision/Housekeeping)
- [Electronics](https://github.com/Haptic-Vision/Electronics)
- [Software-stack](https://github.com/Haptic-Vision/Software-stack)

# Software-stack
To setup and run the device use the following steps:

<img src="https://github.com/Haptic-Vision/haptic_vision/blob/main/Documentation/map%20pulse.gif" width=300 height=500>

## To run
1. Update raspberry pi
```bash
sudo apt update
sudo apt upgrade
```
2. Install OpenCV
```bash
sudo apt install libopencv-dev
sudo apt install libopencv-core-dev
```

3. Setup Pi Cam
Once the ribbon cable is connected to the rasperry pi. Got to raspberry pi configurator
```bash
sudo raspi-config
```
4. Go to interface and enable camera option. Then restart you Pi.
5. Once Pi is restarted, check of camera is working by
```bash
libcamera-jpeg -o image.jpg
```
6. If raspicam dependencies are not installed, follow steps in the following link
```bash
https://github.com/cedricve/raspicam
```
7. Clone program files onto the rasperry pi.
8. Go to the yolo directory and run the following to compile and run the system
```bash
g++ -std=c++11 -o yolo yolo.cpp `pkg-config opencv4 --cflags --libs` -lraspicam -lraspicam_cv -lopencv_highgui -DWITH_QT -Wno-psabi -pthread -lwiringPi
./yolo
```
# Circuit Design

<img src="https://github.com/Haptic-Vision/haptic_vision/blob/main/Electronics/elec.png" width=300 height=500>
