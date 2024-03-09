cmake_minimum_required(VERSION 3.5)

project(12_9_datei_schreiben_beliebig LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12_9_datei_schreiben_beliebig main.cpp)

install(TARGETS 12_9_datei_schreiben_beliebig
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
