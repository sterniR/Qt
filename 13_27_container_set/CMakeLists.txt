cmake_minimum_required(VERSION 3.5)

project(13_27_container_set LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_27_container_set main.cpp)

include(GNUInstallDirs)
install(TARGETS 13_27_container_set
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
