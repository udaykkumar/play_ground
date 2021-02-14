#include <benchmark/benchmark.h>
#include <LC_E_0002.hpp>

static void BM_LC_E_0002_reverse(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    lc::reverse(state.range(0));
  }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0002_reverse)->Range(8, 128<<10);


static void BM_LC_E_0002_reverse_Method_2(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    lc::reverse_Method_2(state.range(0));
  }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0002_reverse_Method_2)->Range(8, 128<<10);

