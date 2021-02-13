#include <benchmark/benchmark.h>
#include <22_07_2019.hpp>

static void BM_22_07_2019_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    daily_interview::binary_tree binay_tree;
    state.PauseTiming();
	for( size_t i = 0 ; i < state.range(0); i ++ )
		binay_tree.add(rand());
	state.ResumeTiming();
	binay_tree.invert();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_22_07_2019_Solution)->Range(8, 8<<10);

