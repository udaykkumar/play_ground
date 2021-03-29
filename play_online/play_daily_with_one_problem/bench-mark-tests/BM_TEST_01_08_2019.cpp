#include <benchmark/benchmark.h>
#include <01_08_2019.hpp>

static void CustomArguments(benchmark::internal::Benchmark* b) {
  for (int i = 2; i <= 15; ++i)
      b->Args({i});
}

static void BM_01_08_2019_num_ways(benchmark::State& state) 
{
    // Perform setup here
    for (auto _ : state) 
         daily_interview::num_ways(state.range(0),state.range(0)) ;
  
}
// Register the function as a benchmark
BENCHMARK(BM_01_08_2019_num_ways)->Apply( CustomArguments );


static void BM_01_08_2019_num_ways_better(benchmark::State& state) 
{
    // Perform setup here
    for (auto _ : state) 
         daily_interview::num_ways_better(state.range(0),state.range(0)) ;
  
}
// Register the function as a benchmark
BENCHMARK(BM_01_08_2019_num_ways_better)->Apply( CustomArguments );



static void BM_01_08_2019_num_ways_even_better(benchmark::State& state) 
{
    // Perform setup here
    for (auto _ : state) 
         daily_interview::num_ways_even_better(state.range(0),state.range(0)) ;
  
}
// Register the function as a benchmark
BENCHMARK(BM_01_08_2019_num_ways_even_better)->Apply( CustomArguments );