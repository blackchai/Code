cmake_minimum_required(VERSION 3.10)

project(opencv_learn)

find_package(OpenCV)

# add_executable(exercise_1 exercise_1.cpp)
# target_link_libraries(exercise_1 ${OpenCV_LIBRARIES})

# add_executable(exercise_2 exercise_2.cpp)
# target_link_libraries(exercise_2 ${OpenCV_LIBRARIES})

# add_executable(exercise_3 exercise_3.cpp)
# target_link_libraries(exercise_3 ${OpenCV_LIBRARIES})

# add_executable(exercise_4 exercise_4.cpp)
# target_link_libraries(exercise_4 ${OpenCV_LIBRARIES})

# add_executable(exercise_7 exercise_7.cpp)
# target_link_libraries(exercise_7 ${OpenCV_LIBRARIES})

# add_executable(exercise_8 exercise_8.cpp)
# target_link_libraries(exercise_8 ${OpenCV_LIBRARIES})

add_executable(exercise_6 exercise_6.cpp)
target_link_libraries(exercise_6 ${OpenCV_LIBRARIES})