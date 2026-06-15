#include <LC_E_0013.hpp>
#include <iostream>

namespace lc
{

int maxSubArray(std::vector<int> &nums)
{
	int max_sum = (1 << ((sizeof(int) * 8) - 1));
	int sum = 0;
	for (auto n : nums)
	{
		sum = std::max(sum + n, n);
		max_sum = std::max(sum, max_sum);
	}
	return max_sum;
}
}

