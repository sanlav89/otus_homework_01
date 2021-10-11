# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
project(otus_homework_01 VERSION 0.0.1)

# CONFIGURE VERSION
configure_file (
    version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/version.h
)

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
add_executable(otus_homework_01 ${SOURCES} ${HEADERS})

# PROPERTIES
set_target_properties (
    otus_homework_01 PROPERTIES
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
)

# INCLUDEPATH
target_include_directories (
    otus_homework_01 PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
