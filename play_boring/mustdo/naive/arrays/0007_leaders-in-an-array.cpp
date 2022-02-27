/*
 https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

 Given an array of positive integers. Your task is to find the leaders in the array.
 Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, the rightmost element is always a leade
 */

#include <iostream>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream &os, const std::vector<int> &v)
{
	for (auto a : v)
		os << a << " ";
	os << "\n";
	return os;
}

std::vector<int> get_leavers_in_an_array(std::vector<int> array)
{
	std::vector<int> v;

	auto it = array.rbegin();
	v.push_back(*it);
	for (++it; it != array.rend(); it++)
	{
		if (*it >= v.back())
			v.push_back(*it);
	}

	// This is stupid...
	std::reverse(v.begin(), v.end());

	return v;
}

void get_leavers_in_an_array_test_1()
{
	std::vector<int> v =
	{ 16, 17, 4, 3, 5, 2 };
	std::cout << get_leavers_in_an_array(v) << std::endl;
	return;
}

void get_leavers_in_an_array_test_2()
{
	std::vector<int> v =
	{ 1, 2, 3, 4, 0 };
	std::cout << get_leavers_in_an_array(v) << std::endl;
	return;
}

void get_leavers_in_an_array_test_3()
{
	std::vector<int> v =
	{ 7, 4, 5, 7, 3 };
	std::cout << get_leavers_in_an_array(v) << std::endl;
	return;
}
int main()
{
	get_leavers_in_an_array_test_1();
	get_leavers_in_an_array_test_2();
	get_leavers_in_an_array_test_3();
	return 0;
}
