# Minimum CMake
cmake_minimum_required(VERSION 2.8...3.22)
project(stack)
enable_testing()


# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.c")
file(GLOB TEST_SOURCES "test/*.c")

include_directories("public/inc")

add_executable("stack-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("stack-test" ${Boost_LIBRARIES})

add_library("stack" STATIC ${PROBLEM_SOURCES})
add_test( NAME stack-test COMMAND stack-test )