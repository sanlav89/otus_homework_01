# CMAKE VERSION
cmake_minimum_required(VERSION 3.5)

# PROJECT
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(auto_tuple VERSION ${PROJECT_VESRION})

# SOURCES

# HEADERS

# LIBRARIES

# PROJECT
add_executable(auto1 auto1.cpp)
add_executable(auto2 auto2.cpp)
add_executable(tuple1 tuple1.cpp)
add_executable(tuple2 tuple2.cpp)

# PROPERTIES
set_target_properties (
    auto1
    auto2
    tuple1
    tuple2
        PROPERTIES
        CMAKE_CXX_STANDARD 17
        CMAKE_CXX_STANDARD_REQUIRED ON
)

# INCLUDEPATH

# Linking

# Compiler options
if (MSVC)
    target_compile_options(auto1 PRIVATE
        /W4
    )
    target_compile_options(auto2 PRIVATE
        /W4
    )
    target_compile_options(tuple1 PRIVATE
        /W4
    )
    target_compile_options(tuple2 PRIVATE
        /W4
    )
else ()
    target_compile_options(auto1 PRIVATE
        -Wall -Wextra -pedantic
    )
    target_compile_options(auto2 PRIVATE
        -Wall -Wextra -pedantic
    )
    target_compile_options(tuple1 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(tuple2 PRIVATE
        -Wall -Wextra -pedantic -Werror -std=c++17
    )
endif()
