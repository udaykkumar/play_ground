#include <benchmark/benchmark.h>
#include <accounts_merge.hpp>

static void BM_accounts_merge_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    /* Solution Here */
  }
}
// Register the function as a benchmark
BENCHMARK(BM_accounts_merge_Solution);

