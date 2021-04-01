#include <benchmark/benchmark.h>
#include <LC_E_0012.hpp>

static void BM_LC_E_0012_countAndSay(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		lc::countAndSay((state.range() % 29));
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0012_countAndSay)->Range(8, 8 << 10);

