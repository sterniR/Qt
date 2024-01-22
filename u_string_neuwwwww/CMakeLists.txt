cmake_minimum_required(VERSION 3.5)

project(u_string_neuwwwww LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(u_string_neuwwwww main.cpp)

install(TARGETS u_string_neuwwwww
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
