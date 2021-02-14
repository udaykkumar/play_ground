
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
set(CMAKE_PROJECT_VERSION 		"0")
set(CMAKE_PROJECT_VERSION_MAJOR "0")
set(CMAKE_PROJECT_VERSION_MINOR "0")
set(CMAKE_PROJECT_VERSION_PATCH "0")

project (cphb)
enable_testing()

#Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost  COMPONENTS unit_test_framework  REQUIRED )


#Project Compiler Arguments
# -std=c++2a is for clang .. and this obviously needs tuning
# SET(PROJECT_COMPILER_FLAGS "-std=c++2a ")
#SET(PROJECT_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage -std=c++2a ")
#SET(PROJECT_LINK_FLAGS    "-lgcov")

#Project SourceFiles
file(GLOB PROBLEM_SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB BM_SOURCES "bench-mark-tests/*.cpp" )

#Project Includes
include_directories( "./src"  "./tests")



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${PROJECT_COMPILER_FLAGS} ")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_LINK_FLAGS}")


add_executable("cphb" ${PROBLEM_SOURCES} ${TEST_SOURCES})
target_link_libraries("cphb" ${Boost_LIBRARIES} )

add_executable("cphb-bm" ${PROBLEM_SOURCES} ${BM_SOURCES})
target_link_libraries("cphb-bm" benchmark )

add_test(NAME cphb COMMAND cphb)

