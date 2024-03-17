cmake_minimum_required(VERSION 3.5)

project(u_kopf_csv_windows LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(u_kopf_csv_windows main.cpp)

install(TARGETS u_kopf_csv_windows
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
