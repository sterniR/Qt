cmake_minimum_required(VERSION 3.5)

project(13_36_bitset_operator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_36_bitset_operator main.cpp)

install(TARGETS 13_36_bitset_operator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
