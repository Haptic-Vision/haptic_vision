cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(HViz)

SET(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(TORCH_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/libtorch")

set(CMAKE_PREFIX_PATH ${TORCH_ROOT})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

find_package(OpenCV REQUIRED)
find_package(Torch REQUIRED)
find_package(GTest REQUIRED)

set(SOURCES
    src/main.cpp
    lib/camera/CameraCapture.cpp
    lib/yolo/Yolo.cpp
    lib/obstacle_detector/ObstacleDetector.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/yolo
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/obstacle_detector
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(HViz_run ${SOURCES})
add_executable(test_CameraCapture ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera/test_CameraCapture.cpp)

add_library(HViz_lib STATIC ${SOURCES})
add_library(CameraCapture
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera/CameraCapture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera/test_CameraCapture.cpp
)

target_include_directories(HViz_lib PUBLIC ${OpenCV_INCLUDE_DIRS} ${TORCH_INCLUDE_DIRS})

target_link_libraries(HViz_run HViz_lib ${OpenCV_LIBS} ${TORCH_LIBRARIES})
target_link_libraries(test_CameraCapture HViz_lib)
target_link_libraries(test_CameraCapture ${OpenCV_LIBS})
target_link_libraries(test_CameraCapture CameraCapture)
target_link_libraries(test_CameraCapture gtest gtest_main)
target_link_libraries(CameraCapture HViz_lib)
target_link_libraries(HViz_lib CameraCapture)
target_link_libraries(test_CameraCapture HViz_lib CameraCapture gtest gtest_main pthread)

add_dependencies(test_CameraCapture CameraCapture)

set_property(TARGET HViz_run PROPERTY CXX_STANDARD 14)
