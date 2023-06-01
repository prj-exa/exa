cmake_minimum_required (VERSION 3.26)

project ("EXA"
          LANGUAGES C
          HOMEPAGE_URL "https://github.com/prj-exa/exa"
          DESCRIPTION "Implementation of cross-platform network c library."
          VERSION 1.0.0)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/bootstrap.cmake")

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include (ccache)
include (Findjansson)

add_subdirectory (libkodik)

option (EXA_ENABLE_TESTING "" ON)

if (EXA_ENABLE_TESTING)
  include (CTest)
  option (BUILD_TESTS OFF)
  add_subdirectory (vendor/munit)
  add_subdirectory (tests)
endif ()
