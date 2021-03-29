#include <benchmark/benchmark.h>
#include <logger_rate_limiter.hpp>

static void BM_logger_rate_limiter_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		/* Solution Here */
	}
}
// Register the function as a benchmark
BENCHMARK(BM_logger_rate_limiter_Solution);

