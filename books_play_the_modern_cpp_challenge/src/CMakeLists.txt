
# Minimum CMake
cmake_minimum_required(VERSION 2.8...3.22)
project( play_the_modern_cpp_challenge )
#enable_testing()


file(GLOB APP_SOURCES *.c**)
foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  add_executable(${testname} ${testsourcefile})
  add_test( NAME ${testname} COMMAND ${testname} )
endforeach(testsourcefile ${APP_SOURCES})
