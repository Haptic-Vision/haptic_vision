cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(HViz)
SET(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/libtorch)

find_package(OpenCV REQUIRED)
find_package(Torch REQUIRED)

set(SOURCES
    src/YOLOv5LibTorch.cpp
    lib/camera/CameraCapture.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(HViz_run ${SOURCES})

target_link_libraries(HViz_run ${OpenCV_LIBS} ${TORCH_LIBRARIES})
set_property(TARGET HViz_run PROPERTY CXX_STANDARD 14)
