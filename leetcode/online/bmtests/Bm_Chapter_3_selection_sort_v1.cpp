#include <benchmark/benchmark.h>
#include <numeric>
#include <random>
#include <algorithm>
#include <Chapter_3_selection_sort.h>

static void Bm_Chapter_1_selection_sort_random(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();

		std::vector<int> iv;

		for (decltype(state.range(0)) i = 0; i < state.range(0); i++)
			iv.emplace_back(i);

		std::vector<int> ov(iv.size());

		std::copy(iv.begin(), iv.end(), ov.begin());

		std::shuffle(iv.begin(), iv.end(), std::mt19937
		{ std::random_device
		{ }() });

		state.ResumeTiming();

		cphb::selection_sort_v1(iv);
	}
}
// Register the function as a benchmark
BENCHMARK(Bm_Chapter_1_selection_sort_random)->Range(8, 8 << 10);
