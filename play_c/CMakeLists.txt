
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (c)
enable_testing()

#This one for my Mac setup
set(CMAKE_CXX_STANDARD 17)

# Project Compiler Arguments
set(PROJECT_COMPILER_FLAGS " -Wall -fprofile-arcs -ftest-coverage  -std=c++11 ")
set(PROJECT_LINK_FLAGS "-lgcov --coverage")

add_subdirectory( graph )
add_subdirectory( list  )
add_subdirectory( queue )
add_subdirectory( stack )
add_subdirectory( tree  )