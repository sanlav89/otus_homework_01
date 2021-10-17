# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
set(PATCH_VERSION "12" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(otus_homework_01 VERSION ${PROJECT_VESRION})

# SUBDIRECTORIES
add_subdirectory(helloworld)
#add_subdirectory(ip_filter)
#add_subdirectory(unit_tests)

# CONFIGURE VERSION
configure_file (
    version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/version.h
)
