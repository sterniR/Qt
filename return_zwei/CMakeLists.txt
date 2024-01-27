cmake_minimum_required(VERSION 3.5)

project(return_zwei LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(return_zwei main.cpp)

include(GNUInstallDirs)
install(TARGETS return_zwei
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
