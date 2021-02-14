#include <benchmark/benchmark.h>
#include <LC_E_0011.hpp>

static void BM_LC_E_0011_searchInsert(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> v;
        for (int i = 0; i <= state.range(); ++i)
        {
            v.push_back(i);
        }
        state.ResumeTiming();
        lc::searchInsert(v, state.range() + 1);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0011_searchInsert)->Range(8, 8<<10);

