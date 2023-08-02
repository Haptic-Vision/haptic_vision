# HapticVision (aka "HViz")
A device that helps perceive your surrounding by using the sense of touch with deployment of YOLOv5 through LibTorch C++ API.

# Requirements
- [Ubuntu 18.04](https://www.instructables.com/Install-Ubuntu-18044-LTS-on-Your-Raspberry-Pi-Boar/)
- OpenCV 3.2.0
- [LibTorch 1.6.0](https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip)
- [CMake 3.10.2](https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line)
- [piGPIO](https://abyz.me.uk/rpi/pigpio/download.html)

# Software-stack
To setup and run the device use the following steps:

## To run
1. Update raspberry pi
```bash
sudo apt update
sudo apt upgrade
```
2. Install pigpio
```bash
sudo apt-get install libpigpio-dev
```

3. Install Qt
```bash
sudo apt-get install qtdeclarative5-dev-tools
sudo apt-get install libqwt-qt5-dev
```

4. Install OpenCV
```bash
sudo apt install libopencv-dev
sudo apt install libopencv-core-dev
```

5. Setup Pi Cam
Once the ribbon cable is connected to the rasperry pi. Got to raspberry pi configurator
```bash
sudo raspi-config
```
6. Go to interface and enable camera option. Then restart you Pi.

7. Once Pi is restarted, check of camera is working by
```bash
libcamera-jpeg -o image.jpg
```
8. If raspicam dependencies are not installed, follow steps in the following [link](https://github.com/cedricve/raspicam).

9. Clone program files onto the rasperry pi.

10. Compile and run.
```bash
mkdir build && cd build
cmake ..
make
./../bin/HViz_run
```

Note: 
- Libtorch package solely contributes to the presence of python files in the project.
- COCO-pretrained YOLOv5s model has been provided. For more pretrained models, see [yolov5](https://github.com/ultralytics/yolov5).

# Technologies

HViz is built using:

- [C++ Programming Language](https://www.cplusplus.com/)
- [Debian/Ubuntu Linux](https://www.linux.org/)
- [Raspberry Pi](https://www.raspberrypi.org)
- [Cmake](https://cmake.org/)
- [OpenCV](https://opencv.org/)
- [Google Test](https://github.com/google/googletest)
- [Doxygen](https://www.doxygen.nl/index.html)
- [Qt](https://www.qt.io/)

## Socials
- [Instagram](https://www.instagram.com/hapticvision_/)

## The Team
- [rdj2829](https://github.com/rdj2829)
- [dheerajsankar](https://github.com/dheerajsankar)
- [kprakz](https://github.com/kprakz)
- [josephjoel3099](https://github.com/josephjoel3099)

## Contact Us
- DM us on [hapticvision_](https://www.instagram.com/hapticvision_/)
- Email us at [hapticvisionuofg@gmail.com](mailto:hapticvisionuofg@gmail.com)