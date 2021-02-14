//https://leetcode.com/problems/search-insert-position/
/**
35. Search Insert Position
Easy

1811

220

Add to List

Share
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
**/
#ifndef __LC_E_0011_HPP_INCLUDED__
#define __LC_E_0011_HPP_INCLUDED__
#include <vector>
namespace lc 
{
	int searchInsert(std::vector<int>& nums, int target);
}

#endif
