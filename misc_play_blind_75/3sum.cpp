/**
 * 
 Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
 	such that i != j, i != k, and j != k, 
 	 and nums[i] + nums[j] + nums[k] == 0.

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
#include <set>
#include <unordered_map>
#include <algorithm>

class Solution {

	/// -1,0,1,2,-1,-4
	/// -4, -1, -1, 0, 1, 2
	/// -4, 
	/// -1 -1, 2
public:
    std::vector< std::vector<int>> threeSum( std::vector<int>& nums) {

    	const int TargetSum = 0 ;
    	std::vector< std::vector<int> > res;
    	/// handle crisis
    	if ( nums.size() <= 2 ) return res;

    	/// let it be neat and clean and scending
    	std::sort( nums.begin(), nums.end() );
    
    	/// Outer loop runs for 2 less .. keep in mind
    	for ( int i = 0 ; i < int(nums.size())-2; ++i ) {

    		/// We can not find a TargetSum sum anymore 
    		/// if its more than or equal to TargetSum 
    		if ( nums.at(i) > TargetSum ) break;

    		/// for i == 0 - there are no duplicate check
    		/// for i > 0  - eliminate duplicates
    		if ( i == 0 || (i > 0 and nums.at(i) != nums.at(i-1)) ) {

    			/// have two ends merge 
				int  left  = i+1; 
				int  right = nums.size()-1;
				int  sum   = TargetSum - nums.at(i);

				while ( left < right) {

					if ( nums.at(left) + nums.at(right) == sum ) {
						/// this is a triplet sum matching 0 -- do the math
					
						/// save triplet
						res.emplace_back( std::vector<int>{nums.at(i), nums.at(left), nums.at(right)} );

						/// Remove duplicates from left and right
						while (left < right and nums.at(left) == nums.at(left+1)) left++;
                    	while (left < right and nums.at(right) == nums.at(right-1)) right--;

                    	/// advance left and right for next iteration
						left ++;
						right --;

					}else if ( nums.at(left) + nums.at(right) < sum ) {
						/// sum is left heavy ( negative heavy ) offload some
						left ++;
					}else{

						/// sum is right heavy ( positive heavy ) offload some
						right --;
					}
				}			
    		}
    	}
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	
	{
		Solution s;
		std::vector<int> nums { -1,0,1,2,-1,-4 };
		auto res = s.threeSum(nums);
		for ( auto r : res ) {
			std::cout << " { " ;
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
			std::cout << " }  ";
		}
		std::cout << "\n";
	}

	{
		Solution s;
		std::vector<int> nums {0};
		auto res = s.threeSum(nums);
		for ( auto r : res ) {
			std::cout << " { " ;
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
			std::cout << " }  ";
		}
		std::cout << "\n";
	}

	{
		Solution s;
		std::vector<int> nums { };
		auto res = s.threeSum(nums);
		for ( auto r : res ) {
			std::cout << " { " ;
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
			std::cout << " }  ";
		}
		std::cout << "\n";
	}

	{
		Solution s;
		std::vector<int> nums { 0,0,0,0 };
		auto res = s.threeSum(nums);
		for ( auto r : res ) {
			std::cout << " { " ;
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
			std::cout << " }  ";
		}
		std::cout << "\n";
	}
	return 0;
}