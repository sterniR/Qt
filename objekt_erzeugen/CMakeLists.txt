cmake_minimum_required(VERSION 3.5)

project(objekt_erzeugen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(objekt_erzeugen main.cpp)

install(TARGETS objekt_erzeugen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
