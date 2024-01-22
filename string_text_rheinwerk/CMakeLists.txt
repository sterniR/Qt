cmake_minimum_required(VERSION 3.5)

project(string_text_rheinwerk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(string_text_rheinwerk main.cpp)

install(TARGETS string_text_rheinwerk
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
