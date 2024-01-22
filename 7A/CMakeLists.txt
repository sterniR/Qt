cmake_minimum_required(VERSION 3.5)

project(7A LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(7A main.cpp)

install(TARGETS 7A
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
