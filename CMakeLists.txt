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
    lib/gpio_controller/GPIOController.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/yolo
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/gpio_controller
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/obstacle_detector
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(HViz_run ${SOURCES})
add_executable(test_CameraCapture ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera/test_CameraCapture.cpp)
# add_executable(test_ObstacleDetector ${CMAKE_CURRENT_SOURCE_DIR}/lib/obstacle_detector/test_ObstacleDetector.cpp)
# add_executable(test_Yolo ${CMAKE_CURRENT_SOURCE_DIR}/lib/yolo/test_Yolo.cpp)

add_library(HViz_lib STATIC ${SOURCES})
add_library(CameraCapture
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera/CameraCapture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/camera/test_CameraCapture.cpp
)
# add_library(Yolo
#     ${CMAKE_CURRENT_SOURCE_DIR}/lib/yolo/Yolo.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/lib/yolo/test_Yolo.cpp
# )

target_include_directories(HViz_lib PUBLIC ${OpenCV_INCLUDE_DIRS} ${TORCH_INCLUDE_DIRS})

target_link_libraries(HViz_run HViz_lib ${OpenCV_LIBS} ${TORCH_LIBRARIES} pigpio)
target_link_libraries(test_CameraCapture HViz_lib ${OpenCV_LIBS} CameraCapture gtest gtest_main pthread)
target_link_libraries(CameraCapture HViz_lib)
target_link_libraries(HViz_lib PUBLIC pigpio)
# target_link_libraries(test_ObstacleDetector HViz_lib gtest gtest_main pthread)
# target_link_libraries(test_Yolo HViz_lib ${OpenCV_LIBS} Yolo gtest gtest_main pthread)
# target_link_libraries(Yolo HViz_lib)

add_dependencies(test_CameraCapture CameraCapture)
# add_dependencies(test_Yolo Yolo)

set_property(TARGET HViz_run PROPERTY CXX_STANDARD 14)