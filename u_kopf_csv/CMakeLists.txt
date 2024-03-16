cmake_minimum_required(VERSION 3.5)

project(u_kopf_csv LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(u_kopf_csv main.cpp)

include(GNUInstallDirs)
install(TARGETS u_kopf_csv
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
