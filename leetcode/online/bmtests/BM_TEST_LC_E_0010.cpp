#include <benchmark/benchmark.h>
#include <LC_E_0010.hpp>

static void BM_LC_E_0010_strStr(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();
		std::string s1;
		std::string s2 = "BBBB";
		for (int i = 0; i < state.range(); ++i)
			s1 += 'A';

		state.ResumeTiming();
		lc::strStr(s1, s2);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0010_strStr)->Range(8, 8 << 10);

