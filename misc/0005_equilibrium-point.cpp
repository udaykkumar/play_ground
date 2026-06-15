/*
 * https://practice.geeksforgeeks.org/problems/equilibrium-point/0
 *
 * Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
 */

#include <iostream>
#include <vector>

int equilibrium_point(std::vector<size_t> &array)
{
	if (array.size() == 1)
		return 1;

	size_t sumRight
	{ 0 }, sumLeft
	{ 0 }, sum
	{ 0 };

	for (size_t a : array)
		sum += a;

	sumRight = sum;
	sumLeft = 0;
	for (size_t i = 1; i < array.size(); i++)
	{
		sumLeft += array[i - 1];
		sumRight = sum - sumLeft - array[i];

		if (sumLeft == sumRight)
			return (int) i + 1;

	}

	return -1;

}

void equilibrium_point_test_1()
{
	std::vector<size_t> array =
	{ 1, 3, 5, 2, 2 };
	std::cout << equilibrium_point(array) << std::endl;
}

void equilibrium_point_test_2()
{
	std::vector<size_t> array =
	{ 1 };
	std::cout << equilibrium_point(array) << std::endl;
}

int main()
{
	equilibrium_point_test_1();
	equilibrium_point_test_2();
	return 0;
}
