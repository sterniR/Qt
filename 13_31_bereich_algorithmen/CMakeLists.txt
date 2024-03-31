cmake_minimum_required(VERSION 3.5)

project(13_31_bereich_algorithmen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_31_bereich_algorithmen main.cpp)

install(TARGETS 13_31_bereich_algorithmen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
