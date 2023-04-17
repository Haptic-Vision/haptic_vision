# Software-stack
All of the code required to run the device is here

<img src="https://github.com/Haptic-Vision/Documentation/blob/48967f1653fec708ade78a39c4cb524c40eee959/map%20pulse.gif" width=300 height=500>

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
8. Got to the yolo directory and run the following to compile and run the system
```bash
g++ -std=c++11 -o yolo yolo.cpp `pkg-config opencv4 --cflags --libs` -lraspicam -lraspicam_cv -lopencv_highgui -DWITH_QT -Wno-psabi -pthread -lwiringPi
./yolo
```
