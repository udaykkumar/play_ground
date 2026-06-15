#include <benchmark/benchmark.h>
#include <20_07_2019.hpp>

static void BM_20_07_2019_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		std::vector<int> arr =
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 23 };
		daily_interview::can_it_be_made_non_decreasing(arr);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_20_07_2019_Solution);

