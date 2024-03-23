cmake_minimum_required(VERSION 3.5)

project(13_21_container_queue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_21_container_queue main.cpp)

install(TARGETS 13_21_container_queue
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
