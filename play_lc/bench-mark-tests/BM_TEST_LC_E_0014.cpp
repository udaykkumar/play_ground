#include <benchmark/benchmark.h>
#include <LC_E_0014.hpp>

static void BM_LC_E_0014_lengthOfLastWord(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        state.PauseTiming();
        std::string v;
        for( int i = 0 ; i < state.range(); i ++ )
            v += ( i % 10 ) ? ' ' : 'A' ;
        state.ResumeTiming();

        lc::lengthOfLastWord(v);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0014_lengthOfLastWord)->Range( 8, 8 << 5 );

static void BM_LC_E_0014_lengthOfLastWord_Space_At_Beginning(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        state.PauseTiming();
        std::string v;
        v += ' ';
        for( int i = 0 ; i < state.range(); i ++ )
            v += 'A' ;
        state.ResumeTiming();

        lc::lengthOfLastWord(v);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0014_lengthOfLastWord_Space_At_Beginning)->Range( 8, 8 << 10 );

