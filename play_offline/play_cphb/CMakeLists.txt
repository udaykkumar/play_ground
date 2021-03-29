
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (cphb)
enable_testing()

#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )

#Project Includes
include_directories( "./src"  "./tests")





add_executable("cphb" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("cphb" ${Boost_LIBRARIES} )

add_executable("cphb-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("cphb-bm" benchmark )

add_test(NAME cphb COMMAND cphb)

