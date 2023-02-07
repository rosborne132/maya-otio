# Install script for directory: /Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/libImath-3_2.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImath-3_2.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImath-3_2.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImath-3_2.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Imath" TYPE FILE FILES
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/half.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/halfFunction.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/halfLimits.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathBox.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathBoxAlgo.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathColor.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathColorAlgo.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathEuler.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathExport.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathForward.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathFrame.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathFrustum.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathFrustumTest.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathFun.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathGL.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathGLU.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathInt64.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathInterval.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathLine.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathLineAlgo.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathMath.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathMatrix.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathMatrixAlgo.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathNamespace.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathPlane.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathPlatform.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathQuat.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathRandom.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathRoots.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathShear.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathSphere.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathTypeTraits.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathVec.h"
    "/Users/osbornr/Documents/dev/repos/cpp/maya_plugin_development/devkitBase/plug-ins/plug-ins/maya-otio-file-translator/libs/opentimelineio/src/deps/Imath/src/Imath/ImathVecAlgo.h"
    )
endif()

