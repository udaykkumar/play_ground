
# Minimum CMake
cmake_minimum_required (VERSION 2.8...3.22)
project (play_scheduler)
#enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")


#Project Includes
include_directories( "./src" )



add_executable("scheduler" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("scheduler" ${Boost_LIBRARIES} "pthread" )
