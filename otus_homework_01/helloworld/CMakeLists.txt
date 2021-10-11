# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
project(helloworld VERSION 0.0.1)

# SOURCES
set (
    SOURCES
        main.cpp
#        lib.cpp
)

# HEADERS
set (
    HEADERS
#        lib.h
)

# LIBRARIES
add_library(lib lib.cpp lib.h)

# PROJECT
add_executable(helloworld lib ${SOURCES} ${HEADERS})

# PROPERTIES
set_target_properties (
    lib PROPERTIES
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
)
set_target_properties (
    helloworld PROPERTIES
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
)

set(eee ${CMAKE_CURRENT_BINARY_DIR}/../)

message("***** DIR: ${eee}")

# INCLUDEPATH
target_include_directories (
    lib PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/../
)
target_include_directories (
    helloworld PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/../
)
