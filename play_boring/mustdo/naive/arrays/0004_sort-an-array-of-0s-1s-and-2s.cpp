/*

 https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

 Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.
 */

#include <iostream>
#include <algorithm>
#include <vector>

std::ostream& operator<<(std::ostream &os, const std::vector<int> &array)
{

	for (int a : array)
		os << a << " ";
	os << "\n";
	return os;
}

void sort_an_array_of_0s_1s_and_2s(std::vector<int> &array)
{
	std::vector<int> numCounter =
	{ 0, 0, 0 };
	for (auto v : array)
	{
		numCounter[v]++;
	}

	int i = 0;
	for (int num = 0; num < 3; num++)
	{
		for (int counter = 0; counter < numCounter.at(num); counter++)
			array[i++] = num;
	}

	return;
}

void sort_an_array_of_0s_1s_and_2s_test_1()
{
	std::vector<int> array =
	{ 0, 2, 1, 2 };
	sort_an_array_of_0s_1s_and_2s(array);
	std::cout << array;
}

void sort_an_array_of_0s_1s_and_2s_test_2()
{
	std::vector<int> array =
	{ 0, 1, 0 };
	sort_an_array_of_0s_1s_and_2s(array);
	std::cout << array;
}

void sort_an_array_of_0s_1s_and_2s_test_3()
{
	std::vector<int> array =
	{ 1, 1, 1, 0, 1, 0, 1, 2, 2, 2, 1, 1, 0, 1, 2, 0, 1, 2, 0, 1, 2 };
	sort_an_array_of_0s_1s_and_2s(array);
	std::cout << array;
}

int main(int ac, char **av)
{
	sort_an_array_of_0s_1s_and_2s_test_1();
	sort_an_array_of_0s_1s_and_2s_test_2();
	sort_an_array_of_0s_1s_and_2s_test_3();
	return 0;
}

