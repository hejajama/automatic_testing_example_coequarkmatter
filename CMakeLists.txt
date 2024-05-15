# stop if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and enable C++ support
project(automatictesting CXX)

set(CMAKE_BUILD_TYPE Release)

# Set C++11 standard - the unit test library used here needs this
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIRS})


add_subdirectory(src)


set_target_properties(qm PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )
set_target_properties(test PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )
     