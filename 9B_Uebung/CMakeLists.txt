cmake_minimum_required(VERSION 3.5)

project(9B_Uebung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9B_Uebung main.cpp)

include(GNUInstallDirs)
install(TARGETS 9B_Uebung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
