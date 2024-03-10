cmake_minimum_required(VERSION 3.5)

project(12_12_stream_lesen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12_12_stream_lesen main.cpp)

install(TARGETS 12_12_stream_lesen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
