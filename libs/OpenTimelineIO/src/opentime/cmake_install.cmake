# Install script for directory: /Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/opentime/errorStatus.h;/usr/local/include/opentime/rationalTime.h;/usr/local/include/opentime/stringPrintf.h;/usr/local/include/opentime/timeRange.h;/usr/local/include/opentime/timeTransform.h;/usr/local/include/opentime/version.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/include/opentime" TYPE FILE FILES
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/errorStatus.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/rationalTime.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/stringPrintf.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/timeRange.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/timeTransform.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libopentime.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib" TYPE STATIC_LIBRARY FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/libopentime.a")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libopentime.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libopentime.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}/usr/local/lib/libopentime.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/opentime/OpenTimeConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/usr/local/share/opentime/OpenTimeConfig.cmake"
         "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/CMakeFiles/Export/9dfa5419c9c7be19d2f5067406be9a41/OpenTimeConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/usr/local/share/opentime/OpenTimeConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/usr/local/share/opentime/OpenTimeConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/opentime/OpenTimeConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/opentime" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/CMakeFiles/Export/9dfa5419c9c7be19d2f5067406be9a41/OpenTimeConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/usr/local/share/opentime/OpenTimeConfig-release.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/usr/local/share/opentime" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentime/CMakeFiles/Export/9dfa5419c9c7be19d2f5067406be9a41/OpenTimeConfig-release.cmake")
  endif()
endif()

