cmake_minimum_required(VERSION 3.15)
project(raytracing)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "")

add_executable(raytracing vector3.cpp main.cpp util.cpp rgbcolor.cpp rgbcolor.h hittable.cpp hittable.h)