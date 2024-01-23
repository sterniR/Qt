cmake_minimum_required(VERSION 3.5)

project(delete_me_later LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(delete_me_later main.cpp)

include(GNUInstallDirs)
install(TARGETS delete_me_later
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
