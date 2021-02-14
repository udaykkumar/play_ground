#!/bin/bash

# We'd expect Argument 1 to be of type "LC_[E|M|H]_xxxx"
[ -n "$1" ] || exit

_Inc_File="src/${1}.hpp"
_Src_File="src/${1}.cpp"
_Tst_File="tests/TEST_${1}.cpp"
_BM_File="bench-mark-tests/BM_TEST_${1}.cpp"

printf "We'll be creating \n\tSourceFile\t:\t${_Src_File}\n\tIncludeFile\t:\t${_Inc_File}\n\tTestFile\t:\t${_Tst_File}\n\tBenchMarkFile\t:\t${_BM_File}\n"

read -p "Press yes to confirm : " confirm
[ "$confirm" != "yes" ] &&  exit


#Create the include file first
if [ ! -f "${_Inc_File}" ]; 
then
cat > "${_Inc_File}" << ENDOFFILE
#ifndef __${1}_HPP_INCLUDED__
#define __${1}_HPP_INCLUDED__

namespace lc 
{
	
}

#endif
ENDOFFILE
fi

#Create Source File

if [ ! -f "${_Src_File}" ]; 
then
cat > "${_Src_File}" << ENDOFFILE
#include <${1}.hpp>

namespace lc
{

}

ENDOFFILE
fi


#Create the TestFile
if [ ! -f "${_Tst_File}" ];
then
cat > "${_Tst_File}" << ENDOFFILE
#include <${1}.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_${1} )

BOOST_AUTO_TEST_CASE( Case_1 )
{

}
BOOST_AUTO_TEST_SUITE_END()

ENDOFFILE
fi



#Create the BMFile
if [ ! -f "${_BM_File}" ]; 
then
cat > "${_BM_File}" << ENDOFFILE
#include <benchmark/benchmark.h>
#include <${1}.hpp>

static void BM_${1}_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    /* Solution Here */
  }
}
// Register the function as a benchmark
BENCHMARK(BM_${1}_Solution);

ENDOFFILE

fi




