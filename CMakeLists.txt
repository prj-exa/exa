cmake_minimum_required (VERSION 3.26)

project ("EXA"
          LANGUAGES C
          HOMEPAGE_URL "https://github.com/prj-exa/exa"
          DESCRIPTION "Implementation of cross-platform network c library."
          VERSION 1.0.0)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/bootstrap.cmake")
include (ccache)
include (Findjansson)

add_subdirectory (libkodik)
