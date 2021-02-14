# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(list)
enable_testing()



#This one for my Mac setup
set(CMAKE_CXX_STANDARD 17)

# Project Compiler Arguments
set(PROJECT_COMPILER_FLAGS " -Wall -fprofile-arcs -ftest-coverage  -std=c++11 ")
set(PROJECT_LINK_FLAGS "-lgcov --coverage")

# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.c")
file(GLOB TEST_SOURCES "test/*.c")

include_directories("public/inc")

add_executable("list-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("list-test" ${Boost_LIBRARIES})

add_library("list" STATIC ${PROBLEM_SOURCES})
add_test(NAME list-test COMMAND list-test)