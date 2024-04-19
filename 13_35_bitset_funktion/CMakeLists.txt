cmake_minimum_required(VERSION 3.5)

project(13_35_bitset_funktion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_35_bitset_funktion main.cpp)

install(TARGETS 13_35_bitset_funktion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
