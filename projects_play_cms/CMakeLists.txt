
# Minimum CMake
cmake_minimum_required (VERSION 2.8...3.22)
project (play_cms)
enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")


#Project Includes
include_directories( "./src" )



add_executable("cms" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("cms" ${Boost_LIBRARIES} "pthread" )
