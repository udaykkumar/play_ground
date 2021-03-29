#include <benchmark/benchmark.h>
#include <14_07_2019.hpp>

static void BM_14_07_2019_001(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    bracket_sequence("(((())))").is_valid();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_14_07_2019_001);


static void BM_14_07_2019_002(benchmark::State& state) 
{
  for (auto _ : state)
  {
  	bracket_sequence("[()]{}").is_valid();
  }
}
BENCHMARK(BM_14_07_2019_002);


static void BM_14_07_2019_003(benchmark::State& state) 
{
  for (auto _ : state)
  {
  	bracket_sequence("({[)]").is_valid();
  }
}
BENCHMARK(BM_14_07_2019_003);


static void BM_14_07_2019_004(benchmark::State& state) 
{
  for (auto _ : state)
  {
  	bracket_sequence("((({[})))").is_valid();
  }
}
BENCHMARK(BM_14_07_2019_004);



static void BM_14_07_2019_005(benchmark::State& state) 
{
  for (auto _ : state)
  {
  	bracket_sequence("((({[})))").is_valid();
  }
}
BENCHMARK(BM_14_07_2019_005);


static void BM_14_07_2019_006(benchmark::State& state) 
{
  for (auto _ : state)
  {
  	bracket_sequence("").is_valid();
  }
}
BENCHMARK(BM_14_07_2019_006);