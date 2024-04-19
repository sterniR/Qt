cmake_minimum_required(VERSION 3.5)

project(friend_funktion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(friend_funktion main.cpp)

include(GNUInstallDirs)
install(TARGETS friend_funktion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
