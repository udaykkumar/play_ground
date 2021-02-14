
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (daily-problem)
enable_testing()

#Curses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})



#Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost  COMPONENTS unit_test_framework  REQUIRED )
add_definitions(-DNCURSES_NOMACROS)

#find_package(Boost  COMPONENTS program_options filesystem system log thread log_setup  REQUIRED )


#Project Compiler Arguments
SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
SET(PROJECT_LINK_FLAGS    "-lgcov")

#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )


#Project Includes
include_directories( "./src" )



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${PROJECT_COMPILER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_LINK_FLAGS}")


add_executable("daily-problem" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("daily-problem" ${Boost_LIBRARIES} )
target_link_libraries("daily-problem" ${CURSES_LIBRARIES})

add_executable("daily-problem-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("daily-problem-bm" benchmark )
target_link_libraries("daily-problem-bm" ${CURSES_LIBRARIES})


add_test(NAME daily-problem COMMAND daily-problem )
