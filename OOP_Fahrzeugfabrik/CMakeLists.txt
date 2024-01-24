cmake_minimum_required(VERSION 3.5)

project(OOP_Fahrzeugfabrik LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOP_Fahrzeugfabrik main.cpp)

include(GNUInstallDirs)
install(TARGETS OOP_Fahrzeugfabrik
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
