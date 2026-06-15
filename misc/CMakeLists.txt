
# Minimum CMake
cmake_minimum_required(VERSION 2.8...3.22)
project( play_misc )
#enable_testing()


file(GLOB APP_SOURCES *.c**)
foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  get_filename_component(baseDir ${testsourcefile} DIRECTORY)
  set( TEST_IN  ${baseDir}/${testname}.in)
  add_executable(${testname} ${testsourcefile})
  if ( EXISTS ${TEST_IN} )
    add_test( NAME ${testname} COMMAND sh -c "$<TARGET_FILE:${testname}> < ${TEST_IN}")
  else()
    add_test( NAME ${testname} COMMAND ${testname} )
  endif()
endforeach(testsourcefile ${APP_SOURCES})
