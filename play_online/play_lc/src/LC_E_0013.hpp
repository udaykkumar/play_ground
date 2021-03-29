//https://leetcode.com/problems/maximum-subarray/
/**
53. Maximum Subarray
Easy

6307

272

Add to List

Share
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
**/
#ifndef __LC_E_0013_HPP_INCLUDED__
#define __LC_E_0013_HPP_INCLUDED__
#include <vector>

namespace lc 
{
	int maxSubArray(std::vector<int>& nums);
}

#endif
