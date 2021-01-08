cmake_minimum_required(VERSION 3.1)
project(oh-dice)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fopenmp")

add_library(ohd
Player.cpp
Ploter.cpp)

link_libraries(ohd)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(main ${PROJECT_SOURCE_DIR}/main.cpp)
