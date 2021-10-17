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
add_executable(test_version test_version.cpp)
add_executable(gtest_version gtest_version.cpp)
set_target_properties (
    test_version
        PROPERTIES
            CMAKE_CXX_STANDARD 11
            CMAKE_CXX_STANDARD_REQUIRED ON
            COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
            INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)
set_target_properties (
    gtest_version
        PROPERTIES
            CMAKE_CXX_STANDARD 11
            CMAKE_CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
    test_version
    lib
    ${Boost_LIBRARIES}
)

gtest_discover_tests(gtest_version)
target_link_libraries(
    gtest_version
    lib
    gtest_main
)

if (MSVC)
    target_compile_options(test_version PRIVATE
        /W4
    )
    target_compile_options(gtest_version PRIVATE
        /W4
    )
else ()
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(gtest_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

# Testing
enable_testing()
add_test(test_version test_version)
add_test(gtest_version gtest_version)
