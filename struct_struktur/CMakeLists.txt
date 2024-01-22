cmake_minimum_required(VERSION 3.5)

project(struct_struktur LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(struct_struktur main.cpp)

install(TARGETS struct_struktur
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
