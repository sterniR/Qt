cmake_minimum_required(VERSION 3.5)

project(math_runden LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(math_runden main.cpp)

include(GNUInstallDirs)
install(TARGETS math_runden
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
