/*
Hi, here's your problem today. This problem was recently asked by Amazon:

Given an array of n positive integers and a positive integer s, find the
minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
one, return 0 instead.

Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2

Explanation: the subarray [4,3] has the minimal length under the problem
constraint.

Here is the method signature:


class Solution:
  def minSubArrayLen(self, nums, s):
    # Fill this in

print Solution().minSubArrayLen([2, 3, 1, 2, 4, 3], 7)
# 2

*/
#include <31_07_2019.hpp>

namespace daily_interview
{
	size_t min_sub_array_len( std::vector<size_t> &arr, size_t s)
	{
		size_t min = 0;
		size_t max = 0;
		size_t min_len = arr.size();
		size_t current_min_len = 0;
		size_t sum = 0;
		while(max < arr.size() || min < arr.size())
		{
			current_min_len = max - min + 1;
			if( min_len > current_min_len )
			{
				min_len = current_min_len;
			}

			if( sum < s &&  max < arr.size() )
			{
				sum += arr[max++];
			}
			else if( sum > s )
			{
				sum -= arr[min++];
			}
			else 
			{
				sum += arr[min++];	
			}

		}	

		return min_len;
	}
}

