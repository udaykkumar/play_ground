
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project(play_online)
enable_testing()


add_subdirectory( play_daily_with_one_problem )
add_subdirectory( play_lc )
add_subdirectory( play_lc_once_again_top_google_questions )



#Project SourceFiles
file(GLOB ALL_PROBLEM_SOURCES "**/src/*.c**")
file(GLOB ALL_PROBLEM_INC "**/src/")
file(GLOB ALL_TEST_SOURCES "**/tests/*TEST*.c**" )
file(GLOB ALL_TEST_INC "**/tests/")

#file(GLOB ALL_BM_SOURCES "**/bench-mark-tests/*.cpp" )

include_directories( ${ALL_PROBLEM_INC}  ${ALL_TEST_INC} )

add_executable("tester" ${ALL_PROBLEM_SOURCES} ${ALL_TEST_SOURCES} "./test/suite-runner.cpp") 
target_link_libraries("tester" ${Boost_LIBRARIES} )
