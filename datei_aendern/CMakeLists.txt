cmake_minimum_required(VERSION 3.5)

project(datei_aendern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(datei_aendern main.cpp)

include(GNUInstallDirs)
install(TARGETS datei_aendern
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
