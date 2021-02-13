# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)

# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "test/*.cpp")

include_directories("inc")

add_executable("double-linked-list-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("double-linked-list-test" ${Boost_LIBRARIES})

add_library("double-linked-list" STATIC ${PROBLEM_SOURCES})
