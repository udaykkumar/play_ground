# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project (graph)
enable_testing()


#Project Compiler Arguments
SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
SET(PROJECT_LINK_FLAGS    "-lgcov")


# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.c")
file(GLOB TEST_SOURCES "test/*.c")

include_directories("public/inc")

add_executable("graph-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("graph-test" ${Boost_LIBRARIES})

add_library("graph" STATIC ${PROBLEM_SOURCES})

add_test(NAME graph-test COMMAND graph-test )