# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget c10 torch_cpu torch_cpu_library torch torch_library)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target c10
add_library(c10 SHARED IMPORTED)

set_target_properties(c10 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target torch_cpu
add_library(torch_cpu SHARED IMPORTED)

set_target_properties(torch_cpu PROPERTIES
  INTERFACE_COMPILE_OPTIONS "\$<\$<COMPILE_LANGUAGE:CXX>:-std=c++14>"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "protobuf::libprotobuf;c10;Threads::Threads;caffe2::mkl;caffe2::mkldnn"
)

# Create imported target torch_cpu_library
add_library(torch_cpu_library INTERFACE IMPORTED)

set_target_properties(torch_cpu_library PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "\$<TARGET_PROPERTY:torch_cpu,INTERFACE_COMPILE_DEFINITIONS>"
  INTERFACE_COMPILE_OPTIONS "\$<TARGET_PROPERTY:torch_cpu,INTERFACE_COMPILE_OPTIONS>"
  INTERFACE_INCLUDE_DIRECTORIES "\$<TARGET_PROPERTY:torch_cpu,INTERFACE_INCLUDE_DIRECTORIES>"
  INTERFACE_LINK_LIBRARIES "-Wl,--no-as-needed,\$<TARGET_FILE:torch_cpu> -Wl,--as-needed;\$<TARGET_PROPERTY:torch_cpu,INTERFACE_LINK_LIBRARIES>"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "\$<TARGET_PROPERTY:torch_cpu,INTERFACE_SYSTEM_INCLUDE_DIRECTORIES>"
)

# Create imported target torch
add_library(torch SHARED IMPORTED)

set_target_properties(torch PROPERTIES
  INTERFACE_LINK_LIBRARIES "torch_cpu_library"
)

# Create imported target torch_library
add_library(torch_library INTERFACE IMPORTED)

set_target_properties(torch_library PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "\$<TARGET_PROPERTY:torch,INTERFACE_COMPILE_DEFINITIONS>"
  INTERFACE_COMPILE_OPTIONS "\$<TARGET_PROPERTY:torch,INTERFACE_COMPILE_OPTIONS>"
  INTERFACE_INCLUDE_DIRECTORIES "\$<TARGET_PROPERTY:torch,INTERFACE_INCLUDE_DIRECTORIES>"
  INTERFACE_LINK_LIBRARIES "-Wl,--no-as-needed,\$<TARGET_FILE:torch> -Wl,--as-needed;\$<TARGET_PROPERTY:torch,INTERFACE_LINK_LIBRARIES>"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "\$<TARGET_PROPERTY:torch,INTERFACE_SYSTEM_INCLUDE_DIRECTORIES>"
)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/Caffe2Targets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# Make sure the targets which have been exported in some other 
# export set exist.
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
foreach(_target "protobuf::libprotobuf" )
  if(NOT TARGET "${_target}" )
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets "${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets} ${_target}")
  endif()
endforeach()

if(DEFINED ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
  if(CMAKE_FIND_PACKAGE_NAME)
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  else()
    message(FATAL_ERROR "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  endif()
endif()
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)