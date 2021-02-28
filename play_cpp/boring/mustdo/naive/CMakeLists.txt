# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project(mustdo_naive)
enable_testing()

 

file( GLOB APP_SOURCES */*.c** )
foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  get_filename_component(baseDir ${testsourcefile} DIRECTORY)
  #message( ${testname} )
  set( TEST_IN  ${baseDir}/${testname}.in)
  #message( ${TEST_IN} )
  add_executable(${testname} ${testsourcefile})
  if ( EXISTS ${TEST_IN})
  	#add_test( NAME ${testname} COMMAND "${testname} < ${TEST_IN}" )
message( "Skipping ${testname} Till we figure a way to handle stdin ")
  else()
  	add_test( NAME ${testname} COMMAND ${testname} )
  endif()
endforeach(testsourcefile ${APP_SOURCES})


