# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)

# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.c")
file(GLOB TEST_SOURCES "test/*.c")

include_directories("public/inc")

add_executable("tree-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("tree-test" ${Boost_LIBRARIES})

add_library("tree" STATIC ${PROBLEM_SOURCES})
