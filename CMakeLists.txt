
# Minimum CMake
cmake_minimum_required (VERSION 3.8.1)
project(play_ground)
set(CMAKE_PROJECT_VERSION       "0")
set(CMAKE_PROJECT_VERSION_MAJOR "0")
set(CMAKE_PROJECT_VERSION_MINOR "0")
set(CMAKE_PROJECT_VERSION_PATCH "0")
enable_testing()


include(cmake/GitUtils.cmake)
#include(cmake/FindGLFW3.cmake)
#include(cmake/FindGLEW.cmake)

#find_package(GLEW REQUIRED)
#find_package(glfw3 REQUIRED)

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


#Curses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} )


if( APPLE )
  message( "-- Detected Apple/MacOS ( include graphics Support ) "  )
  include_directories(${GLFW3_INCLUDE_DIR})
  add_definitions(-DGL_SILENCE_DEPRECATION)
else()
  message( "-- As long as it Ubuntu ( include graphics Support )  "  )
  include_directories(${GLFW3_INCLUDE_DIR})
endif()

#Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost  COMPONENTS unit_test_framework  REQUIRED )
add_definitions(-DNCURSES_NOMACROS)
#find_package(Boost  COMPONENTS program_options filesystem system log thread log_setup  REQUIRED )


#Project Compiler Arguments
 if(APPLE)
    message( "-- Detected Apple/MacOS ( Skipping Coverage ) " )
    SET(PROJECT_COMPILER_FLAGS "-Wall -std=c++17 ")
 else()
    SET(PROJECT_COMPILER_FLAGS "-Wall -fprofile-arcs -ftest-coverage -std=c++17 ")
    SET(PROJECT_LINK_FLAGS    "-lgcov")
 endif()



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${PROJECT_COMPILER_FLAGS} ")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_LINK_FLAGS}")

add_subdirectory( play_offline )
add_subdirectory( play_online )



