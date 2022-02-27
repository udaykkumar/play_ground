#include <iostream>
#include <vector>
#include <unordered_map>

/**
 *

Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


 **/
class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map< int, int > map;
        int i = 0;
        for (auto n : nums)
            map.insert(std::make_pair(n, i++));

        i = 0;
        for ( auto n : nums )
        {
            int y = (target - n);
            auto kv = map.find(y);
            if (kv != map.end() and  kv->second != i)
                return {i, kv->second};
            ++i;
        }

        return { -1, -1};
    }
};

int main(int argc, char const *argv[]) {
    std::cout << " hello two_sum \n";

    Solution s;
    {
        std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8};
        auto res = s.twoSum(nums, 9);
    }

    return 0;
}