#include <benchmark/benchmark.h>
#include <16_07_2019.hpp>

static void BM_16_07_2019_001_List_Add_At_End(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    list l;
    for ( decltype(state.range(0)) i = 0 ; i < state.range(0); i ++ )
      l.add(i);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_16_07_2019_001_List_Add_At_End)->Range(8, 8<<10);



static void BM_16_07_2019_002_List_Add_At_End_Reverse(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    list l;
    for ( decltype(state.range(0)) i = 0 ; i < state.range(0); i ++ )
        l.add(i);
    l.reverse();

  }
}
// Register the function as a benchmark
BENCHMARK(BM_16_07_2019_002_List_Add_At_End_Reverse)->Range(8, 8<<8);

