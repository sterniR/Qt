cmake_minimum_required(VERSION 3.5)

project(9_36_verzeichnis_aendern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9_36_verzeichnis_aendern main.cpp)

include(GNUInstallDirs)
install(TARGETS 9_36_verzeichnis_aendern
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
