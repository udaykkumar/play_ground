#include <Chapter_3_bubble_sort.h>
#include <iostream>
#include <vector>

// Bubble sort makes a simplest of algorithms 
// works at O(n^2) complexity
// this is brute force..
int cphb::bubble_sort_v1(std::vector<int> &v)
{
	int inversions = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v.size() - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				std::swap(v[j], v[j + 1]);
				inversions++;
			}
		}
	}
	return inversions;
}

int cphb::bubble_sort_v2(std::vector<int> &v)
{
	int inversions = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				std::swap(v[j], v[j + 1]);
				inversions++;
			}
		}
	}
	return inversions;
}
