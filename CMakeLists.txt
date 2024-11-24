# Minimum CMake version required
cmake_minimum_required(VERSION 3.20)

# Project name and version
project(MyCppProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable warnings (optional but recommended)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

# Add the executable
add_executable(MyCppExecutable main.cpp)

# Set output directory for the executable
set_target_properties(MyCppExecutable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Link additional libraries if needed (example below, optional)
# target_link_libraries(MyCppExecutable PRIVATE some_library)
