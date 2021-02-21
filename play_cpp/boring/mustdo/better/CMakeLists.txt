# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project( 55_specific_ways_to_improve_your_programs_and_design )

add_compile_options( -std=c++17 )
file( GLOB APP_SOURCES *.c** )
foreach( testsourcefile ${APP_SOURCES} )
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
endforeach( testsourcefile ${APP_SOURCES} )


