# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(cpp)
enable_testing()

# Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(
  Boost
  COMPONENTS unit_test_framework
  REQUIRED)


#Project Compiler Arguments
SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
SET(PROJECT_LINK_FLAGS    "-lgcov")

add_subdirectory(boring)
add_subdirectory(learncpp)
add_subdirectory(libs)
