# HapticVision (aka "HViz")
A device that helps perceive your surrounding by using the sense of touch with deployment of YOLOv5 through LibTorch C++ API.

<img src="https://github.com/Haptic-Vision/haptic_vision/blob/joel_ss/extras/Documentation/pulsating.gif" width="230" height="400">

## The Team
- [@rdj2829](https://github.com/rdj2829)
- [@dheerajsankar](https://github.com/dheerajsankar)
- [@kprakz](https://github.com/kprakz)
- [@josephjoel3099](https://github.com/josephjoel3099)

## Socials
- [Instagram](https://www.instagram.com/hapticvision_/)

# Requirements
- [Ubuntu 18.04](https://www.instructables.com/Install-Ubuntu-18044-LTS-on-Your-Raspberry-Pi-Boar/)
- OpenCV 3.2.0
- [LibTorch 1.6.0](https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip)
- [CMake 3.10.2](https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line)
- [piGPIO](https://abyz.me.uk/rpi/pigpio/download.html)

# Software-stack
To setup and run the device use the following steps:

<img src="https://github.com/Haptic-Vision/haptic_vision/blob/joel_ss/extras/Documentation/map%20pulse.gif" width=300 height=500>

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
6. If raspicam dependencies are not installed, follow steps in the following [link](https://github.com/cedricve/raspicam).

7. Clone program files onto the rasperry pi.
8. Compile and run.
```bash
cd build
cmake ..
make
./../bin/HViz_run
```

Note: COCO-pretrained YOLOv5s model has been provided. For more pretrained models, see [yolov5](https://github.com/ultralytics/yolov5).

# Circuit Design

<img src="https://github.com/Haptic-Vision/haptic_vision/blob/joel_ss/extras/Electronics/elec.png" width=300 height=500>
