#include <benchmark/benchmark.h>
#include <29_07_2019.hpp>

static void BM_29_07_2019_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_29_07_2019_Solution);

