cmake_minimum_required(VERSION 3.5)

project(8B_Loesung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(8B_Loesung main.cpp)

install(TARGETS 8B_Loesung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
