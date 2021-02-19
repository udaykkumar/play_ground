# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project(naive)
enable_testing()

file( GLOB APP_SOURCES */*.c** )
foreach( testsourcefile ${APP_SOURCES} )
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
    add_test( NAME ${testname} COMMAND ${testname} < "${testname}.in" )
endforeach( testsourcefile ${APP_SOURCES} )


