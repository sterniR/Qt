cmake_minimum_required(VERSION 3.5)

project(15_5_pre_weiche LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(15_5_pre_weiche main.cpp)

include(GNUInstallDirs)
install(TARGETS 15_5_pre_weiche
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
