cmake_minimum_required(VERSION 3.5)

project(13_12_container_forward_list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_12_container_forward_list main.cpp)

include(GNUInstallDirs)
install(TARGETS 13_12_container_forward_list
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
