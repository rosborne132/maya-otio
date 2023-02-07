# Install script for directory: /Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Imath" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config/ImathConfig.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config/Imath.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Imath" TYPE FILE FILES
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config/ImathConfig.cmake"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config/ImathConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Imath/ImathTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Imath/ImathTargets.cmake"
         "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config/CMakeFiles/Export/337404c792ddf4581238d79dc7aa1ce1/ImathTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Imath/ImathTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Imath/ImathTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Imath" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config/CMakeFiles/Export/337404c792ddf4581238d79dc7aa1ce1/ImathTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Imath" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/config/CMakeFiles/Export/337404c792ddf4581238d79dc7aa1ce1/ImathTargets-release.cmake")
  endif()
endif()

