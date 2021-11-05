
# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project( play_cpp_data_structures_and_algorithms )
enable_testing()

include_directories(inc)

file(GLOB APP_SOURCES *.c** main/*.c**  )
#file(GLOB APP_LIB_SOURCES "libs/*.c**" )

foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  add_executable(${testname} ${testsourcefile}  )
  add_test( NAME ${testname} COMMAND ${testname} )
endforeach(testsourcefile ${APP_SOURCES})
