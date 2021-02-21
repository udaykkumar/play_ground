
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (play_lc_once_again)
enable_testing()

#Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost  COMPONENTS unit_test_framework  REQUIRED )


#Project Compiler Arguments
if(APPLE)
    message( "-- Detected Apple/MacOS ( Skipping Coverage ) " )
else()
    SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
    SET(PROJECT_LINK_FLAGS    "-lgcov")
endif()

add_compile_options( -std=c++17 )
#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )

#Project Includes
include_directories( "./src" )



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${PROJECT_COMPILER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_LINK_FLAGS}")


add_executable("play_lc_once_again" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("play_lc_once_again" ${Boost_LIBRARIES} )

add_executable("play_lc_once_again-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("play_lc_once_again-bm" benchmark )


add_test( NAME play_lc_once_again COMMAND play_lc_once_again )
