cmake_minimum_required(VERSION 3.5)

project(13_7_container_vector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13_7_container_vector main.cpp)

include(GNUInstallDirs)
install(TARGETS 13_7_container_vector
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
