# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/ErstesFensterCmakeVersuch2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ErstesFensterCmakeVersuch2_autogen.dir/ParseCache.txt"
  "ErstesFensterCmakeVersuch2_autogen"
  )
endif()
