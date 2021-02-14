
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (lc)

include(cmake/GitUtils.cmake)

#Benchmark Find and other stuff
git_clone(
    PROJECT_NAME    googletest
    GIT_URL         https://github.com/google/googletest.git
    GIT_BRANCH      master
    )

add_subdirectory( ${googletest_SOURCE_DIR} )

git_clone(
    PROJECT_NAME    benchmark
    GIT_URL         https://github.com/google/benchmark.git
    GIT_BRANCH      master
    )
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory( ${benchmark_SOURCE_DIR} )



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


