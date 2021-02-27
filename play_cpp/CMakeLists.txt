# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(cpp)
enable_testing()


#Project Compiler Arguments
 if(APPLE)
    message( "-- Detected Apple/MacOS ( Skipping Coverage ) " )
 else()
    SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
    SET(PROJECT_LINK_FLAGS    "-lgcov")
 endif()

add_subdirectory(boring)
add_subdirectory(learncpp)
add_subdirectory(libs)
