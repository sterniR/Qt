cmake_minimum_required(VERSION 3.5)

project(14_9_ausnahme_werfen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(14_9_ausnahme_werfen main.cpp)

install(TARGETS 14_9_ausnahme_werfen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
