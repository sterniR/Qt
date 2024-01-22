cmake_minimum_required(VERSION 3.5)

project(9_2_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9_2_1 main.cpp)

install(TARGETS 9_2_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
