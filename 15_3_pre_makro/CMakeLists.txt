cmake_minimum_required(VERSION 3.5)

project(15_3_pre_makro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(15_3_pre_makro main.cpp)

include(GNUInstallDirs)
install(TARGETS 15_3_pre_makro
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
