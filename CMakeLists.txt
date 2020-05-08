cmake_minimum_required(VERSION 2.8)
project(OpenCV)
 
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} user/local/include/opencv4)

add_subdirectory(chapter2)
add_subdirectory(chapter3)
add_subdirectory(chapter4)