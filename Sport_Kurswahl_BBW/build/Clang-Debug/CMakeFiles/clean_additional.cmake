# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Sport_Kurswahl_BBW_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Sport_Kurswahl_BBW_autogen.dir/ParseCache.txt"
  "Sport_Kurswahl_BBW_autogen"
  )
endif()
