cmake_minimum_required(VERSION 3.26)
project(Password_Manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
add_executable(Password_Manager main.cpp
        mainwindow.cpp
        mainwindow.h)
find_package(Qt5Widgets REQUIRED)

target_link_libraries(Password_Manager Qt5::Widgets)