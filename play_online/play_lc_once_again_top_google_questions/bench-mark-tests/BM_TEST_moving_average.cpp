#include <benchmark/benchmark.h>
#include <moving_average.hpp>

static void BM_moving_average_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_moving_average_Solution);

