#include <benchmark/benchmark.h>
#include <LC_E_0005.hpp>

static void BM_LC_E_0005_longestCommonPrefix(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<std::string> input;

        for( int i = 0; i < state.range(); i ++ )
        {
            input.push_back("Help");
        }
        state.ResumeTiming();

        lc::longestCommonPrefix(input);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0005_longestCommonPrefix)->Range(8, 8<<10);

