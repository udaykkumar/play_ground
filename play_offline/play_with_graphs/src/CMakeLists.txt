
# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project( play_with_graphs )
enable_testing()

include_directories(inc)

file(GLOB APP_SOURCES *.c** main/*.c**  )
file(GLOB IMPL_SOURCES     inc/impl/*.c** )

foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  add_executable(${testname} ${testsourcefile}  ${IMPL_SOURCES} )
  add_test( NAME ${testname} COMMAND ${testname} )
endforeach(testsourcefile ${APP_SOURCES})
