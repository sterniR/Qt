cmake_minimum_required(VERSION 3.5)

project(tik_tak_toe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tik_tak_toe main.cpp)

install(TARGETS tik_tak_toe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
