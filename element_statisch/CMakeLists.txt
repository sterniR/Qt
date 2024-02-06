cmake_minimum_required(VERSION 3.5)

project(element_statisch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(element_statisch main.cpp)

include(GNUInstallDirs)
install(TARGETS element_statisch
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
