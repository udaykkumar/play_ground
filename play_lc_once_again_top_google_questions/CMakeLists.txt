
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (play_lc_once_again_top_google_questions)
enable_testing()



#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )

#Project Includes
include_directories( "./src" )



add_executable("play_lc_once_again_top_google_questions" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("play_lc_once_again_top_google_questions" ${Boost_LIBRARIES} )

add_executable("play_lc_once_again_top_google_questions-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("play_lc_once_again_top_google_questions-bm" benchmark )


add_test( NAME play_lc_once_again_top_google_questions COMMAND play_lc_once_again_top_google_questions )
