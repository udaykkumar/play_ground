
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project (lc)
enable_testing()


#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )
# list(APPEND PROBLEM_SOURCES
#     		src/LC_E_0001.cpp
# 			src/LC_E_0002.cpp
# 			src/LC_E_0003.cpp
# 			src/LC_E_0004.cpp
# 			src/LC_E_0005.cpp
# 			src/LC_E_0006.cpp
# 			src/LC_E_0007.cpp
# 			src/LC_E_0008.cpp
# 			src/LC_E_0009.cpp
# 			src/LC_E_0010.cpp
# 			src/LC_E_0011.cpp
# 			src/LC_E_0012.cpp
# 			src/LC_E_0013.cpp
# 			src/LC_E_0014.cpp
# 			src/LC_E_0015.cpp
# 			src/LC_E_0016.cpp
# 			src/LC_E_0017.cpp
# 			src/LC_E_0018.cpp
# 			src/LC_E_0019.cpp
# 			src/LC_E_0020.cpp
# 			src/LC_E_0021.cpp
# 	)

# list(APPEND TEST_SOURCES
#     		tests/suite-runner.cpp
# 			tests/TEST_LC_E_0001.cpp
# 			tests/TEST_LC_E_0001_Method_2.cpp
# 			tests/TEST_LC_E_0001_Method_3.cpp
# 			tests/TEST_LC_E_0001_Method_4.cpp
# 			tests/TEST_LC_E_0002.cpp
# 			tests/TEST_LC_E_0002_Method_2.cpp
# 			tests/TEST_LC_E_0003.cpp
# 			tests/TEST_LC_E_0003_Method_2.cpp
# 			tests/TEST_LC_E_0003_Method_3_2_Years_Ago.cpp
# 			tests/TEST_LC_E_0004.cpp
# 			tests/TEST_LC_E_0004_Method_2.cpp
# 			tests/TEST_LC_E_0005.cpp
# 			tests/TEST_LC_E_0006.cpp
# 			tests/TEST_LC_E_0007.cpp
# 			tests/TEST_LC_E_0008.cpp
# 			tests/TEST_LC_E_0009.cpp
# 			tests/TEST_LC_E_0010.cpp
# 			tests/TEST_LC_E_0011.cpp
# 			tests/TEST_LC_E_0012.cpp
# 			tests/TEST_LC_E_0013.cpp
# 			tests/TEST_LC_E_0014.cpp
# 			tests/TEST_LC_E_0015.cpp
# 			tests/TEST_LC_E_0016.cpp
# 			tests/TEST_LC_E_0016_Method_2.cpp
# 			tests/TEST_LC_E_0017.cpp
# 			tests/TEST_LC_E_0018.cpp
# 			tests/TEST_LC_E_0019.cpp
# 			tests/TEST_LC_E_0020.cpp
# 			tests/TEST_LC_E_0021.cpp
# 	)


# list(APPEND BM_SOURCES
#     		bench-mark-tests/bench-mark.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0001.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0002.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0003.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0004.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0005.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0006.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0007.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0008.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0009.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0010.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0011.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0012.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0013.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0014.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0015.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0016.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0017.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0018.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0019.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0020.cpp
# 			bench-mark-tests/BM_TEST_LC_E_0021.cpp
# 	)

#Project Includes
include_directories( "./src" )



add_executable("lc" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("lc" ${Boost_LIBRARIES} )

add_executable("lc-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("lc-bm" benchmark )


add_test( NAME lc COMMAND lc )
