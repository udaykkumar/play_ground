/**
 * 
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
**/ 

#include <iostream>
#include <vector>
class Solution {

	int int_min() {
		unsigned int max = 0;
 
	    // Computing NOT of 0
	    max = ~max;
	     
	    // 1 time arithmetic right shift
	    max = max >> 1;
	     
	    // Computing INT_MIN
	    int min = max;
	     
	    // INT_MIN = ~INT_MAX
	    min = ~min;

	    return min;
	}

public:
	/// its  Kadane's algo ..
    int maxSubArray(std::vector<int>& nums) {
    	int max_sum  = int_min();
    	int sum = 0;
        
        /// for every n in nums
        for ( auto n : nums ) {

        	/// Keep calculating the sum
            sum += n;
            max_sum = std::max( max_sum,  sum );

            /// if sum falls below zero 
            /// reset to zero and do it again
            sum =  ( sum < 0 ) ? 0 : sum;
        }
        
        return max_sum;
    }
};


int main(int argc, char const *argv[])
{
	{
		Solution s;
		std::vector< int > nums{-2,1,-3,4,-1,2,1,-5,4};
		std::cout << " " << s.maxSubArray(nums) << "\n";
	}
	return 0;
}