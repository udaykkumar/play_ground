#include <benchmark/benchmark.h>
#include <LC_E_0007.hpp>

static void BM_LC_E_0007_mergeTwoLists(benchmark::State &state)
{
	// Perform setup here
	for (auto _ : state)
	{
		lc::ListNode *l1 = new lc::ListNode(-1);
		lc::ListNode *l2 = new lc::ListNode(-1);
		int i = 0;

		state.PauseTiming();

		i = 2;
		for (lc::ListNode *c = l1; i < state.range(); c = c->next)
			c->next = new lc::ListNode(i++);

		i = 2;
		for (lc::ListNode *c = l2; i < state.range(); c = c->next)
			c->next = new lc::ListNode(i++);

		state.ResumeTiming();

		lc::mergeTwoLists(l1, l2);
	}
}
// Register the function as a benchmark
BENCHMARK(BM_LC_E_0007_mergeTwoLists)->Range(2, 8 << 5);

