cmake_minimum_required(VERSION 3.5)

project(9_4_4_math_pruefen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9_4_4_math_pruefen main.cpp)

include(GNUInstallDirs)
install(TARGETS 9_4_4_math_pruefen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
