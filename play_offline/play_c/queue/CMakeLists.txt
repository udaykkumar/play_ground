# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(queue)
enable_testing()



# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.c")
file(GLOB TEST_SOURCES "test/*.c")

include_directories("public/inc")

add_executable("queue-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("queue-test" ${Boost_LIBRARIES})

add_library("queue" STATIC ${PROBLEM_SOURCES})
add_test(NAME queue-test COMMAND queue-test)