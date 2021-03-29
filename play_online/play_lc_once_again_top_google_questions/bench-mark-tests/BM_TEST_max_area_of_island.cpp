#include <benchmark/benchmark.h>
#include <max_area_of_island.hpp>

static void BM_max_area_of_island_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_max_area_of_island_Solution);

