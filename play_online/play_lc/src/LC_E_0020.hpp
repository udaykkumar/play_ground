//https://leetcode.com/problems/merge-sorted-array/
/**
88. Merge Sorted Array
Easy

1674

3572

Add to List

Share
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
**/

#ifndef __LC_E_0020_HPP_INCLUDED__
#define __LC_E_0020_HPP_INCLUDED__
#include <vector>

namespace lc 
{
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
}

#endif
