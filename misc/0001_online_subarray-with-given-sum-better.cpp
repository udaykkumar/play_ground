/*

 https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

 Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

 */

#include <iostream>
#include <vector>
#include <tuple>

std::tuple<size_t, size_t> subarray_with_given_sum(std::vector<size_t> array,
		size_t sum)
{
	size_t idx = 0, jdx = 0;

	for (; idx < array.size(); idx++)
	{
		size_t sub_array_sum = 0;
		for (jdx = idx; jdx < array.size(); jdx++)
		{
			sub_array_sum += array.at(jdx);
			if (sub_array_sum >= sum)
				break;
		}

		if (sub_array_sum == sum)
			return std::make_pair(idx + 1, jdx + 1);
	}

	return std::make_pair(0, 0);
}

static void exec_tests()
{
	int t;
	std::cin >> t;

	while (t-- > 0)
	{
		int n, sum;
		std::cin >> n >> sum;

		std::vector<size_t> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			std::cin >> x;
			v.push_back(x);
		}

		std::tuple<size_t, size_t> res = subarray_with_given_sum(v, sum);
		if (std::get<0>(res) == std::get<1>(res))
		{
			if (std::get<0>(res) == 0)
			{
				std::cout << "-1" << "\n";
				return;
			}
		}
		std::cout << std::get<0>(res) << " " << std::get<1>(res) << "\n";
	}
}

int main(int ac, char **av)
{
	exec_tests();
	return 0;
}
