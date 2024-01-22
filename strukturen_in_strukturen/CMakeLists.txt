cmake_minimum_required(VERSION 3.5)

project(strukturen_in_strukturen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(strukturen_in_strukturen main.cpp)

install(TARGETS strukturen_in_strukturen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
