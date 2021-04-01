#include <benchmark/benchmark.h>
#include <LC_E_0013.hpp>

static void BM_LC_E_0013_maxSubArray(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();

		std::vector<int> v;
		for (int i = 0; i < state.range(); i++)
			v.push_back(i);
		state.ResumeTiming();

		lc::maxSubArray(v);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0013_maxSubArray)->Range(8, 8 << 10);

