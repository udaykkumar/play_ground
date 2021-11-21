/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

 */
#include <15_11_2021.hpp>

#include <unordered_map>

namespace daily_interview
{
    /// Brute Force or a General acceptable method
    std::vector< int > transform_product_of_all_except_ith( std::vector<int> nums)
    {
        /// 1, 2, 3, 4, 5
        int product = 1;
        for ( auto e : nums )
        {
            product *= e;
        }

        for ( auto &e : nums )
        {
            e = product / e;
        }
        return nums;
    }

   
}

