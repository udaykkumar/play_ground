#include <benchmark/benchmark.h>
#include <insert_interval.hpp>

static void BM_insert_interval_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    /* Solution Here */
  }
}
// Register the function as a benchmark
BENCHMARK(BM_insert_interval_Solution);

