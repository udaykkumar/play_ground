/*
 Hi, here's your problem today. This problem was recently asked by Facebook:

 Given a list of numbers, where every number shows up twice except for one number, find that one number.

 Example:
 Input: [4, 3, 2, 4, 1, 3, 2]
 Output: 1
 Challenge: Find a way to do this using O(1) memory
 */

#include <19_07_2019.hpp>
#include <algorithm>
#include <iostream>

namespace daily_interview
{
struct dup
{
	int first;
	int second;

	dup() :
			first(0), second(0)
	{
	}

	dup(int &f) :
			first(f), second(0)
	{
	}

	dup& operator =(int first)
	{
		this->first = first;
		this->second = 0;

		return *this;
	}

	bool is_non_duplicate()
	{
		return (second & 0x01) ? true : false;
	}

	bool increment_if_duplicate(int n)
	{
		bool ret = false;
		if (first == n)
		{
			second++;
			ret = true;
		}
		return ret;
	}
};

int non_duplicate(std::vector<int> &v)
{
	int pair[2] =
	{ 0, 0 };

	std::sort(v.begin(), v.end());
	pair[0] = v[0];
	for (auto n : v)
	{
		if (n == pair[0])
		{
			pair[1] += 1;
			continue;
		}

		if (pair[1] & 0x01)
		{
			return pair[0];
		}

		pair[0] = n;

	}
	return 0;
}

int non_duplicate_im(std::vector<int> &v)
{
	std::sort(v.begin(), v.end());
	dup d(v[0]);
	for (auto n : v)
	{
		if (d.increment_if_duplicate(n) == false)
		{
			if (d.is_non_duplicate() == true)
			{
				return d.first;
			}
			d = n;
		}
	}
	return 0;
}
}
