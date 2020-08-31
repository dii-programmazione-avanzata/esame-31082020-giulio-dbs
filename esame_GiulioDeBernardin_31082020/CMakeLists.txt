cmake_minimum_required(VERSION 3.15)
project(esame)

set(CMAKE_CXX_STANDARD 17)

add_executable(esame main.cpp src/Individual.cpp src/Simulation.cpp)
target_include_directories(esame PRIVATE include)
