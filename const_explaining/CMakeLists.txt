cmake_minimum_required(VERSION 3.5)

project(const_explaining LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(const_explaining main.cpp)

install(TARGETS const_explaining
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
