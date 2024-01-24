cmake_minimum_required(VERSION 3.5)

project(9C_u_kopf_zahlung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9C_u_kopf_zahlung main.cpp)

include(GNUInstallDirs)
install(TARGETS 9C_u_kopf_zahlung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
