
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project(play_online)
enable_testing()


#Project SourceFiles
file(GLOB ALL_PROBLEM_SOURCES "**/src/*.c**")
file(GLOB ALL_PROBLEM_INC "**/src/")
file(GLOB ALL_TEST_SOURCES "**/tests/*.c**" )
file(GLOB ALL_TEST_INC "**/tests/")

include_directories( ${ALL_PROBLEM_INC}  ${ALL_TEST_INC} )

add_executable("play_online_test" ${ALL_PROBLEM_SOURCES} ${ALL_TEST_SOURCES} "./test/suite-runner.cpp") 
target_link_libraries("play_online_test" ${Boost_LIBRARIES} )
