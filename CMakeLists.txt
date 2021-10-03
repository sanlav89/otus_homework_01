cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
add_executable(test_version test_version.cpp)
add_executable(gtest_version gtest_version.cpp)
add_executable(ip_filter
    ${PROJECT_SOURCE_DIR}/ip_filter/ip_filter.cpp
    ${PROJECT_SOURCE_DIR}/ip_filter/ipaddr.cpp
    ${PROJECT_SOURCE_DIR}/ip_filter/ipaddr.h
    )
add_executable(gtest_ipaddr
    ${PROJECT_SOURCE_DIR}/ip_filter/gtest_ipaddr.cpp
    ${PROJECT_SOURCE_DIR}/ip_filter/ipaddr.cpp
    ${PROJECT_SOURCE_DIR}/ip_filter/ipaddr.h
    )

set_target_properties(
    helloworld_cli
    helloworld
    test_version
    gtest_version
    ip_filter
    gtest_ipaddr
    PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# Google Test <-- end

target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_cli PRIVATE
    helloworld
)
target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)
target_link_libraries(
  gtest_version
  gtest_main
  helloworld
)
target_link_libraries(gtest_ipaddr
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(gtest_version)
gtest_discover_tests(gtest_ipaddr)

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(helloworld PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
    target_compile_options(gtest_version PRIVATE
        /W4
    )
    target_compile_options(ip_filter PRIVATE
        /W4
    )
    target_compile_options(gtest_ipaddr PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(gtest_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(gtest_ipaddr PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



#install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
add_test(gtest_version gtest_version)
add_test(gtest_ipaddr gtest_ipaddr)
