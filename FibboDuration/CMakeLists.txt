cmake_minimum_required(VERSION 3.5)

project(FibboDuration LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FibboDuration main.cpp)

install(TARGETS FibboDuration
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
