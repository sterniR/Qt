# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WeitereWidgets_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WeitereWidgets_autogen.dir\\ParseCache.txt"
  "WeitereWidgets_autogen"
  )
endif()
