# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(ip_filter VERSION ${PROJECT_VESRION})

# SOURCES
set (
    SOURCES
        ip_filter.cpp
        ipaddr.cpp
)

# HEADERS
set (
    HEADERS
        ipaddr.h
)

# LIBRARIES

# PROJECT
add_executable(ip_filter ${SOURCES} ${HEADERS})

# PROPERTIES
set_target_properties (
    ip_filter PROPERTIES
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
)

# INCLUDEPATH

# Linking

# Compiler options
if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

### Unit Tests

# GoogleTest package
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Tests exe
add_executable(gtest_ipaddr gtest_ipaddr.cpp ipaddr.cpp)
set_target_properties (
    gtest_ipaddr
        PROPERTIES
            CMAKE_CXX_STANDARD 11
            CMAKE_CXX_STANDARD_REQUIRED ON
)

gtest_discover_tests(gtest_ipaddr)
target_link_libraries(
    gtest_ipaddr
    gtest_main
)

if (MSVC)
    target_compile_options(gtest_ipaddr PRIVATE
        /W4
    )
else ()
    target_compile_options(gtest_ipaddr PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

# Testing
enable_testing()
add_test(gtest_ipaddr gtest_ipaddr)
