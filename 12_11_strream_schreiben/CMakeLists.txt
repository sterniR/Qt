cmake_minimum_required(VERSION 3.5)

project(12_11_strream_schreiben LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12_11_strream_schreiben main.cpp)

install(TARGETS 12_11_strream_schreiben
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
