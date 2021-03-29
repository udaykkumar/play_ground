#include <benchmark/benchmark.h>
#include <LC_E_0009.hpp>

static void BM_LC_E_0009_removeElement_last_element(benchmark::State &state)
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
        lc::removeElement(v, state.range()-1);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0009_removeElement_last_element)->Range(8, 8 << 10);


static void BM_LC_E_0009_removeElement_first_element(benchmark::State &state)
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
        lc::removeElement(v, 0);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0009_removeElement_first_element)->Range(8, 8 << 10);

