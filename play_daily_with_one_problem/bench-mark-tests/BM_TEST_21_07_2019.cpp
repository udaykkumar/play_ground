#include <benchmark/benchmark.h>
#include <21_07_2019.hpp>

static void BM_21_07_2019_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    daily_interview::bst bst;

	for( size_t i = 0 ; i < state.range(0); i ++ )
		bst.add( static_cast<int>(rand()) );
	
  }
}
// Register the function as a benchmark
BENCHMARK(BM_21_07_2019_Solution)->Range(8, 8<<10);

