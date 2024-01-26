cmake_minimum_required(VERSION 3.5)

project(9_20_kommando LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9_20_kommando main.cpp)

include(GNUInstallDirs)
install(TARGETS 9_20_kommando
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
