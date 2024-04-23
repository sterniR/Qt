cmake_minimum_required(VERSION 3.5)

project(14_22_template_klasse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(14_22_template_klasse main.cpp)

include(GNUInstallDirs)
install(TARGETS 14_22_template_klasse
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
