# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project(binary-tree)
enable_testing()


set(PROJECT_COMPILER_FLAGS " -Wall -fprofile-arcs -ftest-coverage  -std=c++11 ")
set(PROJECT_LINK_FLAGS "-lgcov --coverage")

#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES    "test/*.cpp")


include_directories( "inc" )

add_executable("binary-tree-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries( "binary-tree-test"  ${Boost_LIBRARIES}  )

add_library("binary-tree" STATIC ${PROBLEM_SOURCES} )
add_test( NAME binary-tree-test COMMAND binary-tree-test)
