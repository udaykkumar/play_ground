/*
 Hi, here's your problem today. This problem was recently asked by Google:

 Given a list of numbers with only 3 unique numbers (1, 2, 3), sort the list in O(n) time.

 Example 1:
 Input: [3, 3, 2, 1, 3, 2, 1]
 Output: [1, 1, 2, 2, 3, 3, 3]
 */

#include <17_07_2019.hpp>

namespace daily_bira
{
void dose::sort()
{
	int a[3] =
	{ 0, 0, 0 };

	/* merge */
	for (auto v : list_)
	{
		a[v - 1] += 1;
	}

	/* Explode */
	size_t index = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			list_[index++] = i + 1;
		}
	}
}
}
