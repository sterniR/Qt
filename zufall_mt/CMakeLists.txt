cmake_minimum_required(VERSION 3.5)

project(zufall_mt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zufall_mt main.cpp)

include(GNUInstallDirs)
install(TARGETS zufall_mt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
