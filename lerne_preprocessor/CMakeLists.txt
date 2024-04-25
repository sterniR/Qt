cmake_minimum_required(VERSION 3.5)

project(lerne_preprocessor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lerne_preprocessor main.cpp)

include(GNUInstallDirs)
install(TARGETS lerne_preprocessor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
