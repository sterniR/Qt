cmake_minimum_required(VERSION 3.5)

project(8A LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(8A main.cpp)

install(TARGETS 8A
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
