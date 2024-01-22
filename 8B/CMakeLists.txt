cmake_minimum_required(VERSION 3.5)

project(8B LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(8B main.cpp)

install(TARGETS 8B
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
