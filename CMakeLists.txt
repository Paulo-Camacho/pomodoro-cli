cmake_minimum_required(VERSION 3.10)
project(pomodoro)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
set(SOURCE_FILES 
    src/main.cpp
    src/Timer.cpp 
    src/Session.cpp 
)
add_executable(pomodoro ${SOURCE_FILES})

# Include the directory for header files
target_include_directories(pomodoro PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Link SFML libraries
target_link_libraries(pomodoro sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
