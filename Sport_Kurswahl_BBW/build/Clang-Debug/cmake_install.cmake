<<<<<<<< HEAD:Sport_Kurswahl_BBW/build/Desktop_Qt_6_5_0_MinGW_64_bit-Debug/cmake_install.cmake
# Install script for directory: C:/Qt/Projects/Qt/Sport_Kurswahl_BBW
========
# Install script for directory: /home/roman/Documents/Qt/Cpluplus_Buch/Sport_Kurswahl_BBW
>>>>>>>> dfd3075279012fc01aa1acda4c8982bf97948052:Sport_Kurswahl_BBW/build/Clang-Debug/cmake_install.cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Sport_Kurswahl_BBW")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw1120_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<<< HEAD:Sport_Kurswahl_BBW/build/Desktop_Qt_6_5_0_MinGW_64_bit-Debug/cmake_install.cmake
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Qt/Projects/Qt/Sport_Kurswahl_BBW/build/Desktop_Qt_6_5_0_MinGW_64_bit-Debug/Sport_Kurswahl_BBW.exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW.exe")
========
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/roman/Documents/Qt/Cpluplus_Buch/Sport_Kurswahl_BBW/build/Clang-Debug/Sport_Kurswahl_BBW")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW")
>>>>>>>> dfd3075279012fc01aa1acda4c8982bf97948052:Sport_Kurswahl_BBW/build/Clang-Debug/cmake_install.cmake
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Qt/Tools/mingw1120_64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/Sport_Kurswahl_BBW.exe")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<<< HEAD:Sport_Kurswahl_BBW/build/Desktop_Qt_6_5_0_MinGW_64_bit-Debug/cmake_install.cmake
file(WRITE "C:/Qt/Projects/Qt/Sport_Kurswahl_BBW/build/Desktop_Qt_6_5_0_MinGW_64_bit-Debug/${CMAKE_INSTALL_MANIFEST}"
========
file(WRITE "/home/roman/Documents/Qt/Cpluplus_Buch/Sport_Kurswahl_BBW/build/Clang-Debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>>> dfd3075279012fc01aa1acda4c8982bf97948052:Sport_Kurswahl_BBW/build/Clang-Debug/cmake_install.cmake
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
