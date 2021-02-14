#include <benchmark/benchmark.h>
#include <LC_E_0015.hpp>

static void BM_LC_E_0015_Solution(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> v;
        for( int i = 0 ; i < state.range(); i ++ )
            v.push_back(i);
        state.ResumeTiming();

        lc::plusOne(v);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0015_Solution)->Range( 8, 8 << 10 );

