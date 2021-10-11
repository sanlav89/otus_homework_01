# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
project(helloworld VERSION 0.0.1)

# SOURCES
set (
    SOURCES
        main.cpp
        lib.cpp
)

# HEADERS
set (
    HEADERS
        lib.h
)

# PROJECT
add_executable(helloworld ${SOURCES} ${HEADERS})

# PROPERTIES
set_target_properties (
    helloworld PROPERTIES
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
)

# INCLUDEPATH
target_include_directories (
    helloworld PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../
)
