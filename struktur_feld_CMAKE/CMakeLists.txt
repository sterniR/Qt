cmake_minimum_required(VERSION 3.5)

project(struktur_feld_CMAKE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(struktur_feld_CMAKE main.cpp)

install(TARGETS struktur_feld_CMAKE
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
