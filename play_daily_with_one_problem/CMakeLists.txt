
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (daily-problem)
enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )


#Project Includes
include_directories( "./src" )


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
