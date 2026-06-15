
# Minimum CMake
cmake_minimum_required (VERSION 2.8...3.22)
project (play_btree_not_working)
#enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")


#Project Includes
include_directories( "./src" )



add_executable("play_btree_not_working" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("play_btree_not_working" ${Boost_LIBRARIES} "pthread" )
