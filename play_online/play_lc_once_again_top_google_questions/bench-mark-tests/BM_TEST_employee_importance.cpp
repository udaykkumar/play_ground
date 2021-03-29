#include <benchmark/benchmark.h>
#include <employee_importance.hpp>

static void BM_employee_importance_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    /* Solution Here */
  }
}
// Register the function as a benchmark
BENCHMARK(BM_employee_importance_Solution);

