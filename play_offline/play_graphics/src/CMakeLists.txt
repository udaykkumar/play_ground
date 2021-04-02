
# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project( 55_specific_ways_to_improve_your_programs_and_design )
enable_testing()

if(APPLE)
  message( "-- Detected Apple/MacOS ( experimental OpenGL ) " )
  file(GLOB APP_SOURCES *.c**)
  foreach(testsourcefile ${APP_SOURCES})
    get_filename_component(testname ${testsourcefile} NAME_WE)
    add_executable(${testname} ${testsourcefile} )
    target_link_libraries(${testname} ${GLFW3_LIBRARY} ${GLWE_LIBRARY} "-framework OpenGL" )
  endforeach(testsourcefile ${APP_SOURCES})
 else()
    message( "-- We do not do graphics thingi yet in non mac " )
 endif()