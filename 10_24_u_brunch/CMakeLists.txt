cmake_minimum_required(VERSION 3.5)

project(10_24_u_brunch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(10_24_u_brunch main.cpp)

include(GNUInstallDirs)
install(TARGETS 10_24_u_brunch
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
