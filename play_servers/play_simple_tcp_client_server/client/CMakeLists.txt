
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (play_simple_tcp_client)
enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")

#Project Includes
include_directories( "./src" )



add_executable("play_simple_tcp_client" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("play_simple_tcp_client" ${Boost_LIBRARIES} "pthread" )
