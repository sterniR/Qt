cmake_minimum_required(VERSION 3.5)

project(13_28_container_map LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_28_container_map main.cpp)

install(TARGETS 13_28_container_map
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
