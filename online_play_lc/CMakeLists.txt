
# Minimum CMake
cmake_minimum_required (VERSION 2.8...3.22)
project(play_online)
#enable_testing()


#Project SourceFiles
file(GLOB ALL_PROBLEM_SOURCES "src/*.c**")
file(GLOB ALL_TEST_SOURCES "tests/*.c**" )

include_directories( "src" "tests" )

add_executable("play_online_test" ${ALL_PROBLEM_SOURCES} ${ALL_TEST_SOURCES} "test/suite-runner.cpp") 
target_link_libraries("play_online_test" ${Boost_LIBRARIES} )
add_test( NAME play_online_test COMMAND play_online_test)