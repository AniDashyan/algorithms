cmake_minimum_required(VERSION 3.10)

project(algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(algorithms main.cpp)
target_include_directories(algorithms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})