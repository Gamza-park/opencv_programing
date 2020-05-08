cmake_minimum_required(VERSION 2.8)
project(test)
 
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} user/local/include/opencv4)


# 2-1
add_executable(2-1_test 2-1.cpp)
target_link_libraries(2-1_test ${OpenCV_LIBS})

# 2-2
add_executable(2-2_test 2-2.cpp)
target_link_libraries(2-2_test ${OpenCV_LIBS})

# 2-3
add_executable(2-3_test 2-3.cpp)
target_link_libraries(2-3_test ${OpenCV_LIBS})

# 2-4
add_executable(2-4_test 2-4.cpp)
target_link_libraries(2-4_test ${OpenCV_LIBS})

# 2-5
add_executable(2-5_test 2-5.cpp)
target_link_libraries(2-5_test ${OpenCV_LIBS})

# 2-6
add_executable(2-6_test 2-6.cpp)
target_link_libraries(2-6_test ${OpenCV_LIBS})

# 2-7
add_executable(2-7_test 2-7.cpp)
target_link_libraries(2-7_test ${OpenCV_LIBS})

# 2-8
add_executable(2-8_test 2-8.cpp)
target_link_libraries(2-8_test ${OpenCV_LIBS})

# 2-9
add_executable(2-9_test 2-9.cpp)
target_link_libraries(2-9_test ${OpenCV_LIBS})

# 2-10
add_executable(2-10_test 2-10.cpp)
target_link_libraries(2-10_test ${OpenCV_LIBS})

# 2-11
add_executable(2-11_test 2-11.cpp)
target_link_libraries(2-11_test ${OpenCV_LIBS})

# 2-12
add_executable(2-12_test 2-12.cpp)
target_link_libraries(2-12_test ${OpenCV_LIBS})

# 2-13
add_executable(2-13_test 2-13.cpp)
target_link_libraries(2-13_test ${OpenCV_LIBS})

# 2-14
add_executable(2-14_test 2-14.cpp)
target_link_libraries(2-14_test ${OpenCV_LIBS})