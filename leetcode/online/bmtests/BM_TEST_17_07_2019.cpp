#include <benchmark/benchmark.h>
#include <17_07_2019.hpp>

static void BM_17_07_2019_001(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		std::vector<int> v, r;
		for (int i = 0; i < state.range(0); i++)
		{
			int rand = (i % 3) + 1;
			v.push_back(rand);
			r.push_back(rand);
		}

		daily_bira::dose d(v);

		d.sort();

		std::sort(r.begin(), r.end());

		std::vector<int>::iterator rIt = r.begin();
		for (std::vector<int>::iterator it = d.get().begin();
				it != d.get().end(); it++, rIt++)
		{
			if (*it != *rIt)
				return;
		}

	}
}
// Register the function as a benchmark
BENCHMARK(BM_17_07_2019_001)->Range(8, 8 << 10);

static void BM_17_07_2019_002_bira_dose(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		state.PauseTiming();
		std::vector<int> v;
		for (int i = 0; i < state.range(0); i++)
		{
			int rand = (i % 3) + 1;
			v.push_back(rand);
		}
		daily_bira::dose d(v);
		state.ResumeTiming();

		d.sort();
	}
}
// Register the function as a benchmark
BENCHMARK(BM_17_07_2019_002_bira_dose)->Range(8, 8 << 10);

static void BM_17_07_2019_003_std_vector(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		std::vector<int> r;
		state.PauseTiming();
		for (int i = 0; i < state.range(0); i++)
		{
			int rand = (i % 3) + 1;
			r.push_back(rand);
		}

		state.ResumeTiming();
		std::sort(r.begin(), r.end());
	}
}
// Register the function as a benchmark
BENCHMARK(BM_17_07_2019_003_std_vector)->Range(8, 8 << 10);

