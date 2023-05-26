if(POLICY CMP0011)
  cmake_policy(SET CMP0011 NEW)
endif()

# Prohibit in-source builds
if("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  message(
    FATAL_ERROR
      "${PROJECT_NAME}: In-source builds of ${PROJECT_NAME} are not supported. Specify a build directory via 'cmake -S <SOURCE DIRECTORY> -B <BUILD_DIRECTORY>' instead."
  )
endif()
file(REMOVE_RECURSE "${CMAKE_SOURCE_DIR}/CMakeCache.txt" "${CMAKE_SOURCE_DIR}/CMakeFiles")

# Use folders for source file organization with IDE generators (Visual Studio/Xcode)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add common module directories to default search path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/common" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/finders")

# Allow selection of common build types via UI
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "RelWithDebInfo"
      CACHE STRING "OBS build type [Release, RelWithDebInfo, Debug, MinSizeRel]" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Release RelWithDebInfo Debug MinSizeRel)
endif()

# Disable exports automatically going into the CMake package registry
set(CMAKE_EXPORT_PACKAGE_REGISTRY FALSE)
# Enable default inclusion of targets' source and binary directory
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
