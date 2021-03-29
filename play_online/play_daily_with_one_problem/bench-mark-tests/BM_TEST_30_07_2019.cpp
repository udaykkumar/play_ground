#include <benchmark/benchmark.h>
#include <30_07_2019.hpp>

static void BM_30_07_2019_001(benchmark::State& state) 
{
  // Perform setup here
  for (auto _ : state) 
  {
    state.PauseTiming(); 
    size_t R = (state.range(0))%1023;
    size_t C = (state.range(0))%1023;
    
    char matrix[1024][1024];
    for( size_t i = 0 ; i < R; i ++ )
    {
      for( size_t j = 0; j < C ; j ++ )
      {
        matrix[i][j] = (char)((rand() % 26) + 65 );
      }
    }
      

     size_t s_len = (rand() % R);
     char s[s_len];

     for( size_t i = 0; i < s_len; i ++ )
     {
        s[i] = (char)((rand() % 26) + 65 );
     }

  state.ResumeTiming(); 
  daily_interview::word_search( matrix, R, C, s, s_len ) ;
    
  }
}
// Register the function as a benchmark
BENCHMARK(BM_30_07_2019_001)->Range(8, 8<<10);

