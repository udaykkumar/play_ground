
# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project( play_graphics )
enable_testing()

file(GLOB APP_SOURCES *.c**)
foreach(testsourcefile ${APP_SOURCES})
  get_filename_component(testname ${testsourcefile} NAME_WE)
  add_executable(${testname} ${testsourcefile} )
  if(APPLE)
    target_link_libraries(${testname} ${GLFW3_LIBRARY} ${GLWE_LIBRARY} "-framework OpenGL" )
  else()
    target_link_libraries(${testname} ${GLFW3_LIBRARY} ${GLWE_LIBRARY} "-lGL -lGLU -lglut" )
  endif()
endforeach(testsourcefile ${APP_SOURCES})
