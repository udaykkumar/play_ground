#include <benchmark/benchmark.h>
#include <merge_intervals.hpp>

static void BM_merge_intervals_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_merge_intervals_Solution);

