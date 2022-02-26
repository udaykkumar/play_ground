/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

 */
#include <15_11_2021.hpp>

#include <unordered_map>
#include <iostream>

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


    /// Suffix and Prefix Product Array
    /// Some sort of Traversal from
    /// left to right and
    /// right to left
    std::vector<int> prefix_product_array( std::vector<int> nums )
    {

        std::vector<int> output(nums.size());

        output[0] = 1;

        std::cout << " nums ";
        for ( auto n : nums ) std::cout << " " << n;
        std::cout << std::endl;

        // left prefix product
        for(size_t i = 1; i < nums.size(); i++)
            output[i] = output[i - 1] * nums[i - 1];
        
        std::cout << " output ";
        for ( auto n : output ) std::cout << " " << n;
        std::cout << std::endl;

        int product = 1;

        for(int i = nums.size() - 1; i >= 0; i--)
        {


            output[i] = output[i] * product;
		    product *= nums[i];
		    std::cout << " output ";
	        for ( auto n : output ) std::cout << " " << n << "(" << product << ")";
	        std::cout << std::endl;
        }

        return output;

    }
}

