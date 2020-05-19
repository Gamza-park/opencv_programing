add_executable(invert_image invert_image.cpp)
target_link_libraries(invert_image ${OpenCV_LIBS})


add_executable(mouse_point mouse_point.cpp)
target_link_libraries(mouse_point ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})


add_executable(trackbar trackbar.cpp)
target_link_libraries(trackbar ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})


add_executable(img_mix img_mix.cpp)
target_link_libraries(img_mix ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(motion_detection motion_detection.cpp)
target_link_libraries(motion_detection ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(threshold threshold.cpp)
target_link_libraries(threshold ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(otzu otzu.cpp)
target_link_libraries(otzu ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(floodFill floodFill.cpp)
target_link_libraries(floodFill ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(integral integral.cpp)
target_link_libraries(integral ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(histogram histogram.cpp)
target_link_libraries(histogram ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(histogram1 histogram1.cpp)
target_link_libraries(histogram1 ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(stretching stretching.cpp)
target_link_libraries(stretching ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})