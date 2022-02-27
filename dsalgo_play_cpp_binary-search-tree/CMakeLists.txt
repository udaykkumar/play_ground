# Minimum CMake
cmake_minimum_required(VERSION 2.8...3.22)
project( binary-search-tree )
#enable_testing()



# Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*")
file(GLOB TEST_SOURCES "test/*")

include_directories("inc")

add_executable("binary-search-tree-test" ${PROBLEM_SOURCES}
                                                ${TEST_SOURCES})
target_link_libraries("binary-search-tree-test" ${Boost_LIBRARIES})

add_library("binary-search-tree" STATIC ${PROBLEM_SOURCES})
add_test( NAME binary-search-tree-test COMMAND binary-search-tree-test)