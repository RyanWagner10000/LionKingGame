# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(LionKingGame VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)  # Replace with your desired C++ version
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(runGame source/main.cpp source/Player.cpp)

#configure header files to pass the version number to the source code (must add target_include_directories to the end of CMakeLists.txt)
# configure_file(player.h)
