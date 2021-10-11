cmake_minimum_required(VERSION 3.5)

project(otus_homework_01 LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(otus_homework_01 main.cpp)

set_target_properties (
        otus_homework_01 PROPERTIES
        CMAKE_CXX_STANDARD 11
        CMAKE_CXX_STANDARD_REQUIRED ON
)
