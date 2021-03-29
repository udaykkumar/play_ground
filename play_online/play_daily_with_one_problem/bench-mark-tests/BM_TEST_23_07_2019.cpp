#include <benchmark/benchmark.h>
#include <23_07_2019.hpp>

static void BM_23_07_2019_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
   daily_interview::stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(2);
	s.push(5);
	s.push(8);
	s.max();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_23_07_2019_Solution);

