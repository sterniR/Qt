# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RechnerEinfach_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RechnerEinfach_autogen.dir\\ParseCache.txt"
  "RechnerEinfach_autogen"
  )
endif()
