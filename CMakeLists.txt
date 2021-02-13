
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)

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




add_subdirectory( daily-problem )


