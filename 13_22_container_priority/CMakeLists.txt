cmake_minimum_required(VERSION 3.5)

project(13_22_container_priority LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_22_container_priority main.cpp)

install(TARGETS 13_22_container_priority
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
