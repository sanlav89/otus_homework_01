# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(helloworld VERSION ${PROJECT_VESRION})

# SOURCES
set (SOURCES main.cpp)

# HEADERS


# LIBRARIES
add_library(lib lib.cpp lib.h)

# PROJECT
add_executable(helloworld lib ${SOURCES})

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

# INCLUDEPATH
target_include_directories (
    lib PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/../
)
target_include_directories (
    helloworld PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/../
)

# Linking

# Compiler options
if (MSVC)
    target_compile_options(helloworld PRIVATE
        /W4
    )
    target_compile_options(lib PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

### Unit Tests

# Boost package
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# GoogleTest package
### TODO

# Tests exe
add_executable(test_version test_version.cpp)
set_target_properties (
    test_version
        PROPERTIES
            CMAKE_CXX_STANDARD 11
            CMAKE_CXX_STANDARD_REQUIRED ON
            COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
            INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(
    test_version
    lib
    ${Boost_LIBRARIES}
)

if (MSVC)
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_test(test_version test_version)
