# HTTP(S) Server in C 

A simple, lightweight HTTP server written in C, designed for learning and embedded applications.

## Features

- Handles basic HTTP/1.1 GET requests
- Serves static text files
- Supports MIME types for common file formats
- Configurable port and root directory

## Requirements

- Linux/Unix system (uses POSIX sockets)
- GNU C compiler (gcc)
- CMake for building the project (minumum 3.10 required)

## Build and Run

```
# Clone the repository
git clone https://github.com/shakyasimha/http-server.git
cd http-server

# Build the project with cmake
mkdir -p build
mkdir -p bin
cd build
cmake ..

# Run the project 
./bin/server
```

## To-do

- Implement full SSL/TLS features 
- Add POST/PUT request
- Implement concurrency and multithreading


