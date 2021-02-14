# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(55_Specific_Ways_To_Improve_Your_Prggrams_And_Design)
enable_testing ()

# Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(
  Boost
  COMPONENTS unit_test_framework
  REQUIRED)

# Project Compiler Arguments
set(PROJECT_COMPILER_FLAGS " -Wall -fprofile-arcs -ftest-coverage  -std=c++11 ")
set(PROJECT_LINK_FLAGS "-lgcov --coverage")

add_subdirectory(src)



