#include <benchmark/benchmark.h>
#include <LC_E_0006.hpp>

static void BM_LC_E_0006_isValid(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();
		std::string input;
		std::string paranthesis = "{}[]()";
		for (int i = 0; i < state.range(); i++)
		{
			input += paranthesis.at(i % 6);
		}
		state.ResumeTiming();

		lc::isValid(input);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0006_isValid)->Range(8, 8 << 10);

