#include <benchmark/benchmark.h>
#include <LC_E_0004.hpp>

static void BM_LC_E_0004_romanToInt(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();
		std::string input;
		for (int i = 0; i < state.range(); i++)
		{
			input += "M";
		}
		state.ResumeTiming();
		lc::romanToInt(input);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0004_romanToInt)->Range(8, 8 << 10);

static void BM_LC_E_0004_romanToInt_Method_2(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();
		std::string input;
		for (int i = 0; i < state.range(); i++)
		{
			input += "M";
		}
		state.ResumeTiming();
		lc::romanToInt_Method_2(input);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0004_romanToInt_Method_2)->Range(8, 8 << 10);
