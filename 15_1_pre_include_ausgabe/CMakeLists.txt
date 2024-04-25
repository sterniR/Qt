cmake_minimum_required(VERSION 3.5)

project(15_1_pre_include_ausgabe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(15_1_pre_include_ausgabe main.cpp)

include(GNUInstallDirs)
install(TARGETS 15_1_pre_include_ausgabe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
