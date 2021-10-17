# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
set(PROJECT_NAME "helloworld" CACHE STRING "Project name")
project(${PROJECT_NAME} VERSION ${PROJECT_VESRION})

# SUBDIRECTORIES
add_subdirectory(helloworld)
add_subdirectory(ip_filter)

# CONFIGURE VERSION
configure_file (
    version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/version.h
)

# Package
if ("${PROJECT_NAME}" STREQUAL "ip_filter")
    install(TARGETS ip_filter RUNTIME DESTINATION bin)
else ()
    install(TARGETS helloworld RUNTIME DESTINATION bin)
endif()
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

# Testing
enable_testing()
