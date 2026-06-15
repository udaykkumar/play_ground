/*
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

 */
#include <17_11_2021.hpp>

#include <set>
#include <iostream>
#include <vector>
namespace daily_interview
{
    /// Brute Force or a General acceptable method
    int firstMissingPositive(std::vector<int> &nums)
    {
        std::set<int> cache;
        int missing_positive = 1;
        for ( auto n : nums )
        {
            if ( n == missing_positive )
            {
                missing_positive ++;
                while ( cache.find(missing_positive) != cache.end() )
                {
                    missing_positive++;
                }
            }
            cache.insert(n);
        }

        return missing_positive;
    }

}

