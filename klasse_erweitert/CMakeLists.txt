cmake_minimum_required(VERSION 3.5)

project(klasse_erweitert LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(klasse_erweitert main.cpp)

include(GNUInstallDirs)
install(TARGETS klasse_erweitert
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
