//https://leetcode.com/problems/two-sum/
/*

 Given an array of integers, return indices of the two numbers such that they add up to a specific target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.

 Example:

 Given nums = [2, 7, 11, 15], target = 9,

 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].

 */

#ifndef __LC_E_0001_HPP_INCLUDED__
#define __LC_E_0001_HPP_INCLUDED__
#include <vector>
#include <iostream>
namespace lc
{
std::vector<int> twoSum_method_1(std::vector<int> &nums, int target);

std::vector<int> twoSum_method_2(std::vector<int> &nums, int target);

std::vector<int> twoSum_method_3(std::vector<int> &nums, int target);

std::vector<int> twoSum_method_4(std::vector<int> &nums, int target);

}

#endif
