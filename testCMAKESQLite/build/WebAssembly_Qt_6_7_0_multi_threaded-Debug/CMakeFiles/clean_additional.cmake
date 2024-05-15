# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/testCMAKESQLite_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/testCMAKESQLite_autogen.dir/ParseCache.txt"
  "testCMAKESQLite_autogen"
  )
endif()
