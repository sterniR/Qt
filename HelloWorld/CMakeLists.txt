# Define the minimum CMAKE version required:
cmake_minimum_required(VERSION 3.0)

# Define the project:
project(HelloWorldFramework C CXX)

# Set C++ stardard:
set(CMAKE_CXX_STANDARD 11)

# Enable automatic include of generated files (like paths.h):
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include IMGUI (which already includes GLFW):
add_subdirectory(lib/imgui-1.88)

# Include GLAD for OpenGL 3.3 Core functionalities:
add_subdirectory(lib/glad)

# Define all source files we want to compile:
set(SOURCES
    src/main.cpp
)

# Define executables with source files and resources:
add_executable(HelloWorldFramework ${SOURCES})

# Forward CMAKE_SOURCE_DIR to avoid copying files:
target_compile_definitions(HelloWorldFramework PUBLIC -DCMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

# Link against the libraries:
target_link_libraries(HelloWorldFramework PUBLIC imgui glad)
