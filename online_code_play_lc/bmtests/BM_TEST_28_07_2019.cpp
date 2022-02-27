#include <benchmark/benchmark.h>
#include <28_07_2019.hpp>

static void BM_28_07_2019_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		std::vector<int> v =
		{ 1, 2, 1, 2, 1, 2, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1,
				2, 1, 2 };
		daily_interview::find_sequence(v);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_28_07_2019_Solution);

