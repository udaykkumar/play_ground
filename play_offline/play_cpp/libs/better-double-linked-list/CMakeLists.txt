# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project(better-double-linked-list)
enable_testing()




#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES    "test/*.cpp")


include_directories( "inc" )

add_executable("better-double-linked-list-test" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries( "better-double-linked-list-test"  ${Boost_LIBRARIES}  )

add_library("better-double-linked-list" STATIC ${PROBLEM_SOURCES} )

add_test( NAME better-double-linked-list-test COMMAND better-double-linked-list-test)