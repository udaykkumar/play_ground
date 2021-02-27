
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (daily-problem)
enable_testing()


#Project Compiler Arguments
 if(APPLE)
    message( "-- Detected Apple/MacOS ( Skipping Coverage ) " )
 else()
    SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage ")
    SET(PROJECT_LINK_FLAGS    "-lgcov")
 endif()

add_compile_options( -std=c++17 )

#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )


#Project Includes
include_directories( "./src" )



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${PROJECT_COMPILER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_LINK_FLAGS}")


add_executable("daily-problem" ${PROBLEM_SOURCES} ${TEST_SOURCES})
#add_executable("daily-problem" "tests/suite-runner.cpp" 
#								"src/01_08_2019.cpp" "tests/TEST_01_08_2019.cpp")
target_link_libraries("daily-problem" ${Boost_LIBRARIES} )
target_link_libraries("daily-problem" ${CURSES_LIBRARIES})

add_executable("daily-problem-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
#add_executable("daily-problem-bm" "bench-mark-tests/bench-mark.cpp"
#								"src/01_08_2019.cpp" "bench-mark-tests/BM_TEST_01_08_2019.cpp")
target_link_libraries("daily-problem-bm" benchmark )
target_link_libraries("daily-problem-bm" ${CURSES_LIBRARIES})


add_test(NAME daily-problem COMMAND daily-problem )
