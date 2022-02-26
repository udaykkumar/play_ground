# Minimum CMake
cmake_minimum_required(VERSION 2.8...3.22)
project(list)
enable_testing()


# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.c")
file(GLOB TEST_SOURCES "test/*.c")

include_directories("public/inc")

add_executable("list-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("list-test" ${Boost_LIBRARIES})

add_library("list" STATIC ${PROBLEM_SOURCES})
add_test(NAME list-test COMMAND list-test)