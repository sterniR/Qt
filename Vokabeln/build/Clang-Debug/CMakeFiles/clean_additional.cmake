# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Vokabeln_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Vokabeln_autogen.dir/ParseCache.txt"
  "Vokabeln_autogen"
  )
endif()
