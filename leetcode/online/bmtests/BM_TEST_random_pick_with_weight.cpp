#include <benchmark/benchmark.h>
#include <random_pick_with_weight.hpp>

static void BM_random_pick_with_weight_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_random_pick_with_weight_Solution);

