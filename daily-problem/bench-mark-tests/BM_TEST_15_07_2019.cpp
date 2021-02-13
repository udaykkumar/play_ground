#include <benchmark/benchmark.h>
#include <15_07_2019.hpp>

static void BM_15_07_2019_001(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    std::vector<int> input = {1,3,3,5,7,8,9,9,9,15};
    int target = 9;
    std::pair<int, int> result = bounds(input, target);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_15_07_2019_001);



static void BM_15_07_2019_002(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    std::vector<int> input = {100, 150, 150, 153};
    int target = 150;
    std::pair<int, int> result = bounds(input, target);
    
  }
}
// Register the function as a benchmark
BENCHMARK(BM_15_07_2019_002);


static void BM_15_07_2019_003(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    std::vector<int> input = {1,2,3,4,5,6,10};
    int target = 9;
    std::pair<int, int> result = bounds(input, target);
    
  }
}
// Register the function as a benchmark
BENCHMARK(BM_15_07_2019_003);
