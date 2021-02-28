#include <benchmark/benchmark.h>
#include <02_08_2019.hpp>

static void BM_02_08_2019_Solution(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    state.PauseTiming();
    daily_interview::list l1, l2;

    for( decltype(state.range(0)) i = 0; i <= state.range(0); i ++ )
        l1.add(i);

    for( decltype(state.range(0)) i = state.range(0); i <= (state.range(0) * 2); i ++ )
        l2.add(i);
    state.ResumeTiming(); 
    daily_interview::intersection(l1,l2);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_02_08_2019_Solution)->Arg(8)->Arg(64)->Arg(512)
                                 ->Arg(1<<10)->Arg(8<<10)->Arg(16<<10)->Arg(32<<10)
                                 ->Arg(64<<10)->Arg(128<<10)->Arg(256<<10)->Arg(512<<10);

