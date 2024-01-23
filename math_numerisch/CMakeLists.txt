cmake_minimum_required(VERSION 3.5)

project(math_numerisch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(math_numerisch main.cpp)

include(GNUInstallDirs)
install(TARGETS math_numerisch
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
