cmake_minimum_required(VERSION 3.5)

project(auto_oop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(auto_oop main.cpp)

include(GNUInstallDirs)
install(TARGETS auto_oop
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
