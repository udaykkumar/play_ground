
# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project( play_btree )
enable_testing()



file(GLOB APP_SOURCES play_*.c**)
foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  add_executable(${testname} ${testsourcefile} client_common.cpp)
  target_link_libraries(${testname} ${Boost_LIBRARIES} "pthread" )
endforeach(testsourcefile ${APP_SOURCES})
