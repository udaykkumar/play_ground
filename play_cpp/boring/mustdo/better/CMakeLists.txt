# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)

add_compile_options( -std=c++17 )
file( GLOB APP_SOURCES *.c** )
foreach( testsourcefile ${APP_SOURCES} )
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
endforeach( testsourcefile ${APP_SOURCES} )


