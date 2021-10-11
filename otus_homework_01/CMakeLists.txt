# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
project(otus_homework_01 VERSION 0.0.1)

# SUBDIRECTORIES
add_subdirectory(helloworld)
#add_subdirectory(ip_filter)
#add_subdirectory(unit_tests)

# CONFIGURE VERSION
configure_file (
    version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/version.h
)
