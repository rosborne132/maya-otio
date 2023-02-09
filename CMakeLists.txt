cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME maya-otio)
project(${PROJECT_NAME})

include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)
include_directories(include)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

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

build_plugin()
