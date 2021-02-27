
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (play_lc_once_again_top_google_questions)
enable_testing()



#Project SourceFiles
#file(GLOB PROBLEM_SOURCES "src/*.cpp")
list(APPEND PROBLEM_SOURCES
    		src/accounts_merge.cpp
			src/employee_importance.cpp
			src/Hello_There.cpp
			src/logger_rate_limiter.cpp
			src/max_area_of_island.cpp
			src/merge_intervals.cpp
			src/moving_average.cpp
			src/random_pick_with_weight.cpp
			src/two_sum.cpp
	)

#file(GLOB TEST_SOURCES "tests/*.cpp")
list(APPEND TEST_SOURCES
    		tests/suite-runner.cpp
			tests/TEST_accounts_merge.cpp
			tests/TEST_employee_importance.cpp
			tests/TEST_Hello_There.cpp
			tests/TEST_logger_rate_limiter.cpp
			tests/TEST_max_area_of_island.cpp
			tests/TEST_merge_intervals.cpp
			tests/TEST_moving_average.cpp
			tests/TEST_random_pick_with_weight.cpp
			tests/TEST_two_sum.cpp
	)

#file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )
list(APPEND BM_SOURCES
    		bench-mark-tests/bench-mark.cpp
			bench-mark-tests/BM_TEST_accounts_merge.cpp
			bench-mark-tests/BM_TEST_employee_importance.cpp
			bench-mark-tests/BM_TEST_Hello_There.cpp
			bench-mark-tests/BM_TEST_logger_rate_limiter.cpp
			bench-mark-tests/BM_TEST_max_area_of_island.cpp
			bench-mark-tests/BM_TEST_merge_intervals.cpp
			bench-mark-tests/BM_TEST_moving_average.cpp
			bench-mark-tests/BM_TEST_random_pick_with_weight.cpp
			bench-mark-tests/BM_TEST_two_sum.cpp
	)

#Project Includes
include_directories( "./src" )



add_executable("play_lc_once_again_top_google_questions" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("play_lc_once_again_top_google_questions" ${Boost_LIBRARIES} )

add_executable("play_lc_once_again_top_google_questions-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("play_lc_once_again_top_google_questions-bm" benchmark )


add_test( NAME play_lc_once_again_top_google_questions COMMAND play_lc_once_again_top_google_questions )
