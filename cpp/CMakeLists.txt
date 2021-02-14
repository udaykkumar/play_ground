# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(CPP)

# Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(
  Boost
  COMPONENTS unit_test_framework
  REQUIRED)

#This one for my Mac setup
set(CMAKE_CXX_STANDARD 17)

# Project Compiler Arguments
set(PROJECT_COMPILER_FLAGS " -Wall -fprofile-arcs -ftest-coverage  -std=c++11 ")
set(PROJECT_LINK_FLAGS "-lgcov --coverage")

add_subdirectory(boring)
add_subdirectory(learncpp)
add_subdirectory(libs)
