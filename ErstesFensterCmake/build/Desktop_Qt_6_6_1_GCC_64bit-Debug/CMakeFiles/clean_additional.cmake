# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ErstesFensterCmake_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ErstesFensterCmake_autogen.dir/ParseCache.txt"
  "ErstesFensterCmake_autogen"
  )
endif()
