cmake_minimum_required(VERSION 3.5)

project(Uni-bremen_HelloWorld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Uni-bremen_HelloWorld main.cpp)

install(TARGETS Uni-bremen_HelloWorld
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
