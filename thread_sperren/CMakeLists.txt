cmake_minimum_required(VERSION 3.5)

project(thread_sperren LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(thread_sperren main.cpp)

include(GNUInstallDirs)
install(TARGETS thread_sperren
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
