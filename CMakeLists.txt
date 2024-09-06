cmake_minimum_required(VERSION 3.10)  # Minimum version of CMake
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(pomodoro src/main.cpp)

