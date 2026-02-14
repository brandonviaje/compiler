cmake_minimum_required(VERSION 3.20)

project(semp)

set(CMAX_CXX_STANDARD_20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(semp src/main.cpp)
