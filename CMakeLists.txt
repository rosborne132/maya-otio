cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME maya-otio)
project(${PROJECT_NAME})

include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)
include_directories(include)

set(OTIO_SHARED_LIBS OFF)
add_subdirectory("libs/OpenTimelineIO")
include_directories(
  ${PROJECT_SOURCE_DIR}/libs/OpenTimelineIO/src
  ${PROJECT_SOURCE_DIR}/libs/OpenTimelineIO/src/deps
  ${PROJECT_SOURCE_DIR}/libs/OpenTimelineIO/src/deps/optional-lite/include
)

file(GLOB SOURCES "src/*.cpp")

set(SOURCE_FILES ${SOURCES})
set(LIBRARIES
    OpenMaya
    Foundation
)

find_package(OTIO::opentimelineio)
build_plugin()
