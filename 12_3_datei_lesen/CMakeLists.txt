cmake_minimum_required(VERSION 3.5)

project(12_3_datei_lesen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12_3_datei_lesen main.cpp)

include(GNUInstallDirs)
install(TARGETS 12_3_datei_lesen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
