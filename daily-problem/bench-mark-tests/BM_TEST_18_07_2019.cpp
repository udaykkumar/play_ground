#include <benchmark/benchmark.h>
#include <18_07_2019.hpp>

static void BM_18_07_2019_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    std::vector<int> v = {1,2,3,4,5,6,7,8,0};
    int 			 k = -1;
	daily_interview::two_sum_exists(v, k) ;
  }
}
// Register the function as a benchmark
BENCHMARK(BM_18_07_2019_Solution);

