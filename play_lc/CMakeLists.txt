
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (lc)
enable_testing()

#Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost  COMPONENTS unit_test_framework  REQUIRED )


#Project Compiler Arguments
#SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
#SET(PROJECT_LINK_FLAGS    "-lgcov")

#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )

#Project Includes
include_directories( "./src"  "benchmark/include/")



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${PROJECT_COMPILER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_LINK_FLAGS}")


add_executable("lc" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("lc" ${Boost_LIBRARIES} )

add_executable("lc-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("lc-bm" benchmark )


add_test( NAME lc COMMAND lc )
