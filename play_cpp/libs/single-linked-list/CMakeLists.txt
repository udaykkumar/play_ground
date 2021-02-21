# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project("single-linked-list")
enable_testing()

#Project Compiler Arguments
 if(APPLE)
    message( "-- Detected Apple/MacOS ( Skipping Coverage ) " )
 else()
    SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
    SET(PROJECT_LINK_FLAGS    "-lgcov")
 endif()


# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "test/*.cpp")

include_directories("inc")

add_executable("single-linked-list-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("single-linked-list-test" ${Boost_LIBRARIES})

add_library("single-linked-list" STATIC ${PROBLEM_SOURCES})
add_test( NAME "single-linked-list-test" COMMAND "single-linked-list-test")