#include <benchmark/benchmark.h>
#include <19_07_2019.hpp>

static void BM_19_07_2019_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    std::vector<int> input = {4, 3, 2, 4, 1, 3, 2};
    daily_interview::non_duplicate_im(input);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_19_07_2019_Solution);

