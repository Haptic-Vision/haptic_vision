cmake_minimum_required(VERSION 3.0)
project(HViz)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add the source files
set(SOURCES
    src/main.cpp
    lib/camera/CameraCapture.cpp
    lib/object_detection/ObjectDetection.cpp
)

# Set the include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/object_detection
    ${OpenCV_INCLUDE_DIRS}
)

# Create the executable
add_executable(hviz_run ${SOURCES})

# Link against OpenCV libraries
target_link_libraries(hviz_run ${OpenCV_LIBRARIES})
