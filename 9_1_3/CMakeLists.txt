cmake_minimum_required(VERSION 3.5)

project(9_1_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9_1_3 main.cpp)

install(TARGETS 9_1_3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
