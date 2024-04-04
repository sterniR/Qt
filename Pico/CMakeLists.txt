cmake_minimum_required(VERSION 3.15)

project(Pico LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--no-entry -Wl,--allow-undefined -Wl,--export-all -nostdlib") # -Wl,--strip-all
set(CMAKE_CXX_FLAGS "-nostdlib -fvisibility=hidden --target=wasm32")
set(CMAKE_C_FLAGS "-nostdlib -fvisibility=hidden --target=wasm32")
set(CMAKE_EXECUTABLE_SUFFIX ".wasm")


add_executable(Pico main.cpp)

include(GNUInstallDirs)
install(TARGETS Pico
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
