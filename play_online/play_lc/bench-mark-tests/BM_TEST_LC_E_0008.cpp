#include <benchmark/benchmark.h>
#include <LC_E_0008.hpp>

static void BM_LC_E_0008_removeDuplicates(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> v;
        for (int i = 0; i < state.range(); ++i)
        {
            v.push_back(i);
        }
        state.ResumeTiming();
        lc::removeDuplicates(v);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0008_removeDuplicates)->Range(8, 8 << 10 );


static void BM_LC_E_0008_removeDuplicates_Case_2(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> v;
        for (int i = 0; i < state.range(); ++i)
        {
            v.push_back(i);
            v.push_back(i);
            v.push_back(i);
        }
        state.ResumeTiming();
        lc::removeDuplicates(v);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0008_removeDuplicates_Case_2)->Range(8, 8 << 10 );

