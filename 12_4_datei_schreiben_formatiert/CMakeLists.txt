cmake_minimum_required(VERSION 3.5)

project(12_4_datei_schreiben_formatiert LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12_4_datei_schreiben_formatiert main.cpp)

include(GNUInstallDirs)
install(TARGETS 12_4_datei_schreiben_formatiert
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
