cmake_minimum_required(VERSION 3.5)

project(13_23_pair LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_23_pair main.cpp)

include(GNUInstallDirs)
install(TARGETS 13_23_pair
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
