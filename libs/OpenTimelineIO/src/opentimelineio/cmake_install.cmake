# Install script for directory: /Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio

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
   "/usr/local/include/opentimelineio/any.h;/usr/local/include/opentimelineio/anyDictionary.h;/usr/local/include/opentimelineio/anyVector.h;/usr/local/include/opentimelineio/clip.h;/usr/local/include/opentimelineio/composable.h;/usr/local/include/opentimelineio/composition.h;/usr/local/include/opentimelineio/deserialization.h;/usr/local/include/opentimelineio/effect.h;/usr/local/include/opentimelineio/errorStatus.h;/usr/local/include/opentimelineio/externalReference.h;/usr/local/include/opentimelineio/freezeFrame.h;/usr/local/include/opentimelineio/gap.h;/usr/local/include/opentimelineio/generatorReference.h;/usr/local/include/opentimelineio/imageSequenceReference.h;/usr/local/include/opentimelineio/item.h;/usr/local/include/opentimelineio/linearTimeWarp.h;/usr/local/include/opentimelineio/marker.h;/usr/local/include/opentimelineio/mediaReference.h;/usr/local/include/opentimelineio/missingReference.h;/usr/local/include/opentimelineio/optional.h;/usr/local/include/opentimelineio/safely_typed_any.h;/usr/local/include/opentimelineio/serializableCollection.h;/usr/local/include/opentimelineio/serializableObject.h;/usr/local/include/opentimelineio/serializableObjectWithMetadata.h;/usr/local/include/opentimelineio/serialization.h;/usr/local/include/opentimelineio/stack.h;/usr/local/include/opentimelineio/stackAlgorithm.h;/usr/local/include/opentimelineio/timeEffect.h;/usr/local/include/opentimelineio/timeline.h;/usr/local/include/opentimelineio/track.h;/usr/local/include/opentimelineio/trackAlgorithm.h;/usr/local/include/opentimelineio/transition.h;/usr/local/include/opentimelineio/typeRegistry.h;/usr/local/include/opentimelineio/unknownSchema.h;/usr/local/include/opentimelineio/vectorIndexing.h;/usr/local/include/opentimelineio/version.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/include/opentimelineio" TYPE FILE FILES
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/any.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/anyDictionary.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/anyVector.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/clip.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/composable.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/composition.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/deserialization.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/effect.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/errorStatus.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/externalReference.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/freezeFrame.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/gap.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/generatorReference.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/imageSequenceReference.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/item.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/linearTimeWarp.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/marker.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/mediaReference.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/missingReference.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/optional.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/safely_typed_any.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/serializableCollection.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/serializableObject.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/serializableObjectWithMetadata.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/serialization.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/stack.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/stackAlgorithm.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/timeEffect.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/timeline.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/track.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/trackAlgorithm.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/transition.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/typeRegistry.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/unknownSchema.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/vectorIndexing.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libopentimelineio.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib" TYPE STATIC_LIBRARY FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/libopentimelineio.a")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libopentimelineio.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libopentimelineio.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}/usr/local/lib/libopentimelineio.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/opentimelineio/OpenTimelineIOConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/usr/local/share/opentimelineio/OpenTimelineIOConfig.cmake"
         "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/CMakeFiles/Export/0998ea1accbedab7bbedf7e9b4ce461e/OpenTimelineIOConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/usr/local/share/opentimelineio/OpenTimelineIOConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/usr/local/share/opentimelineio/OpenTimelineIOConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/opentimelineio/OpenTimelineIOConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/opentimelineio" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/CMakeFiles/Export/0998ea1accbedab7bbedf7e9b4ce461e/OpenTimelineIOConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/usr/local/share/opentimelineio/OpenTimelineIOConfig-release.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/usr/local/share/opentimelineio" TYPE FILE FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/opentimelineio/CMakeFiles/Export/0998ea1accbedab7bbedf7e9b4ce461e/OpenTimelineIOConfig-release.cmake")
  endif()
endif()

