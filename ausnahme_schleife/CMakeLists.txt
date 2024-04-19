cmake_minimum_required(VERSION 3.5)

project(ausnahme_schleife LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ausnahme_schleife main.cpp)

include(GNUInstallDirs)
install(TARGETS ausnahme_schleife
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
