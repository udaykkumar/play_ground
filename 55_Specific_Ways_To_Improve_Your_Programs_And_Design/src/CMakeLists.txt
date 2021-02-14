# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)

file(GLOB APP_SOURCES *.cpp)
foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  add_executable(${testname} ${testsourcefile})
endforeach(testsourcefile ${APP_SOURCES})


file(GLOB APP_SOURCES *.cpp)
foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  add_test(NAME ${testname} COMMAND ${testname})
endforeach(testsourcefile ${APP_SOURCES})
