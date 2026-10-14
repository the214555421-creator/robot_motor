cmake_minimum_required(VERSION 3.16)
project(robot_motor LANGUAGES CXX)
include(CTest)
add_executable(robot_motor 
    main.cpp 
    Motor.cpp
    DriveController.cpp)

 add_executable(robot_tests
    test.cpp
    Motor.cpp
    DriveController.cpp
)

add_test(
    NAME BasicTest
    COMMAND robot_tests
)