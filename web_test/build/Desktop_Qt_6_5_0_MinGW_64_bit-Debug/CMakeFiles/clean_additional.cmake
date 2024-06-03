# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\web_test_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\web_test_autogen.dir\\ParseCache.txt"
  "web_test_autogen"
  )
endif()
