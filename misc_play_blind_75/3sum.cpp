/**
 * 
 Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
**/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector< std::vector<int>> threeSum( std::vector<int>& nums) {

    	/// Define the base case
    	return {};

    }
};

int main(int argc, char const *argv[])
{
	
	{
		Solution s;
		std::vector<int> nums { -1,0,1,2,-1,-4 };
		auto res = s.threeSum(nums);
		for ( auto r : res ) {
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
		}
		std::cout << "\n";
	}

	{
		Solution s;
		std::vector<int> nums {0};
		auto res = s.threeSum(nums);
		for ( auto r : res ) {
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
		}
		std::cout << "\n";
	}

	{
		Solution s;
		std::vector<int> nums { };
		auto res = s.threeSum(nums);
		for ( auto r : res ) {
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
		}
		std::cout << "\n";
	}
	return 0;
}