cmake_minimum_required(VERSION 3.5)

project(14_11_ausnahme_klasse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(14_11_ausnahme_klasse main.cpp)

install(TARGETS 14_11_ausnahme_klasse
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
