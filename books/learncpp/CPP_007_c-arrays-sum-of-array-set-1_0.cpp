/*
 * https://practice.geeksforgeeks.org/problems/c-arrays-sum-of-array-set-1/0
 */

#include <iostream>

int main()
{
	int T;
	for (std::cin >> T; T > 0; T--)
	{
		int x;
		std::cin >> x;

		int sum
		{ 0 };
		for (; x > 0; x--)
		{
			int a;
			std::cin >> a;
			sum += a;
		}

		std::cout << sum << std::endl;

	}

	return (0);
}
