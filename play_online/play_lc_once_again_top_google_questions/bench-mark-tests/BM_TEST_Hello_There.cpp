#include <benchmark/benchmark.h>
#include <Hello_There.hpp>

static void BM_Hello_There_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_Hello_There_Solution);

