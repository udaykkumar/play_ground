#include <benchmark/benchmark.h>
#include <25_07_2019.hpp>

static void BM_25_07_2019_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    std::vector<size_t> v ;
	for( decltype(state.range(0)) i = 1; i < state.range(0); i ++ )
		v.push_back(23);
	
	v[997] = 293;
	v[998] = 285;
	v[996] = 68;
	
	daily_interview::is_there_a_pythagorean_triplet(v) ;
  }
}
// Register the function as a benchmark
BENCHMARK(BM_25_07_2019_Solution)->Range(8, 8<<10);

