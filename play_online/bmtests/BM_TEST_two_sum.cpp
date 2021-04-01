#include <benchmark/benchmark.h>
#include <two_sum.hpp>

static void BM_two_sum_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_two_sum_Solution);

