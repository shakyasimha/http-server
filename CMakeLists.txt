cmake_minimum_required(VERSION 3.10)
project(http-server VERSION 1.0)

# Setting output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# including header files
include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/bin
)

# link third party libraries
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Gathering all the source files 
file(GLOB SOURCES CONFIGURE_DEPENDS
  ${CMAKE_SOURCE_DIR}/src/*.c
)

# define executables
add_executable(server ${SOURCES})

