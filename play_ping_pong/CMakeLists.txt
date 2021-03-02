
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (play_ping_pong)
enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
#file(GLOB TEST_SOURCES "tests/*.cpp")
#file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )

#Project Includes
include_directories( "./src" )



add_executable("play_ping_pong" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("play_ping_pong" ${Boost_LIBRARIES} )
