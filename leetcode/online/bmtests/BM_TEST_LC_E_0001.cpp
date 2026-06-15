#include <benchmark/benchmark.h>
#include <LC_E_0001.hpp>

static void BM_LC_E_0001_twoSum_method_1(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();

		int target = 27;
		std::vector<int> v;
		for (int i = 0; i < state.range(0); i++)
			v.push_back(0);
		v.push_back(13);
		v.push_back(14);

		state.ResumeTiming();
		lc::twoSum_method_1(v, target);

	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0001_twoSum_method_1)->Range(8, 8 << 10);

static void BM_LC_E_0001_twoSum_method_2(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();

		int target = 27;
		std::vector<int> v;
		for (int i = 0; i < state.range(0); i++)
			v.push_back(0);
		v.push_back(13);
		v.push_back(14);

		state.ResumeTiming();
		lc::twoSum_method_2(v, target);

	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0001_twoSum_method_2)->Range(8, 8 << 10);

static void BM_LC_E_0001_twoSum_method_3(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();

		int target = 27;
		std::vector<int> v;
		for (int i = 0; i < state.range(0); i++)
			v.push_back(0);
		v.push_back(13);
		v.push_back(14);

		state.ResumeTiming();
		lc::twoSum_method_3(v, target);

	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0001_twoSum_method_3)->Range(8, 8 << 10);

static void BM_LC_E_0001_twoSum_method_4(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();

		int target = 27;
		std::vector<int> v;
		for (int i = 0; i < state.range(0); i++)
			v.push_back(0);
		v.push_back(13);
		v.push_back(14);

		state.ResumeTiming();
		lc::twoSum_method_4(v, target);

	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0001_twoSum_method_4)->Range(8, 8 << 10);
