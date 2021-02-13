/*
Hi, here's your problem today. This problem was recently asked by Facebook:

You are given a list of numbers, and a target number k. Return whether or not there are two numbers in the list that add up to k.

Example:
Given [4, 7, 1 , -3, 2] and k = 5, 
return true since 4 + 1 = 5.

Try to do it in a single pass of the list.
*/

#include <18_07_2019.hpp>
#include <unordered_set>
namespace daily_interview
{
	bool two_sum_exists(const std::vector<int> &numlist, int k)
	{
		std::unordered_set<int> uset( numlist.begin(), numlist.end());
		for( auto n : numlist )
		{
			if( uset.find(k - n) != uset.end() )
			{
				return true;
			}
		}
		return false;
	}

}