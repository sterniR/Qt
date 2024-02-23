cmake_minimum_required(VERSION 3.5)

project(11_1_ableitung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(11_1_ableitung main.cpp)

include(GNUInstallDirs)
install(TARGETS 11_1_ableitung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
