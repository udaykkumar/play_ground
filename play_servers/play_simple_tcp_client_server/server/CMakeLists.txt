
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (play_simple_tcp_server)
enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")

#Project Includes
include_directories( "./src" )



add_executable("play_simple_tcp_server" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("play_simple_tcp_server" ${Boost_LIBRARIES} "pthread" )
