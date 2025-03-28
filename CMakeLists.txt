## Cmake config
cmake_minimum_required(VERSION 3.10)
project(http_server C)

## c standard and compiler flags 
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra) # Enable warnings

## include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

## set output directory for libraries 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)

## gather source files using glob
set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/main.c
    ${CMAKE_SOURCE_DIR}/src/server.c

    ## Adding more .c files here
)

## create executables
add_executable(http_server ${SOURCES})
