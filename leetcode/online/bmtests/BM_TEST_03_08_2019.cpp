#include <benchmark/benchmark.h>
#include <03_08_2019.hpp>

static void BM_03_08_2019_Solution(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		std::string in = "..R...L..R.";
		std::string out = "..RR.LL..RR";
		daily_interview::falling_dominoes(in);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_03_08_2019_Solution);

