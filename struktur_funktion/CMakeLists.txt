cmake_minimum_required(VERSION 3.5)

project(struktur_funktion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(struktur_funktion main.cpp)

install(TARGETS struktur_funktion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
