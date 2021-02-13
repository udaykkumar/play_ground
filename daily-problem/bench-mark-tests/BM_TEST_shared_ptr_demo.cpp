#include <benchmark/benchmark.h>
#include <shared_ptr_demo.hpp>

static void BM_shared_ptr_demo_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    /* Solution Here */
  }
}
// Register the function as a benchmark
BENCHMARK(BM_shared_ptr_demo_Solution);

