cmake_minimum_required(VERSION 3.5)

project(14_10_ausnahme_funktion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(14_10_ausnahme_funktion main.cpp)

install(TARGETS 14_10_ausnahme_funktion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
