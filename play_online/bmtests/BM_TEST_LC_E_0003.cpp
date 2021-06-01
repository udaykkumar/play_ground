#include <benchmark/benchmark.h>
#include <LC_E_0003.hpp>

static void BM_LC_E_0003_isPalindrome(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		lc::isPalindrome(state.range());
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0003_isPalindrome)->Range(8, 8 << 10);

static void BM_LC_E_0003_isPalindrome_Method_2(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		lc::isPalindrome_Method_2(state.range());
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0003_isPalindrome_Method_2)->Range(8, 8 << 10);

static void BM_LC_E_0003_isPalindrome_Method_3_2_Years_Ago(
		benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		lc::isPalindrome_Method_3_2_Years_Ago(state.range());
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0003_isPalindrome_Method_3_2_Years_Ago)->Range(8, 8 << 10);
