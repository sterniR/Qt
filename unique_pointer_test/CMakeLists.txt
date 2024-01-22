cmake_minimum_required(VERSION 3.5)

project(unique_pointer_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unique_pointer_test main.cpp)

install(TARGETS unique_pointer_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
