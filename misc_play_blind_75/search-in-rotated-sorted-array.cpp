

/**
 *

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104


 **/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {


public:
    int search(std::vector<int>& nums, int target) {
    	int lo = 0;
    	int hi = nums.size()-1;

    	while ( lo <= hi ) {
    		/// This is the correct way to calculate mid
    		/// start + ( end - start ) /2  
    		int mid = lo + ((hi - lo) >> 1);

    		/// Got what we need
    		if ( nums[mid] == target )  return mid;
    		
    		if ( nums[mid] >= nums[lo] ) { 
    			/// sorted from lo to mid 

				if ( target >= nums[lo] and target < nums[mid] )
					/// Its within this list bring down hi to within this list
					hi = mid-1;
				else
					/// its in other list
					lo = mid+1;
			
			} else {
				 /// unsorted part

				if ( target <= nums[hi] and target > nums[mid] )
					/// Its within this list .. bring up the lo 
					lo = mid + 1;
				else
					/// its in other part .. move hi down
					hi = mid -1;
			}	
    	}
       
       return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    {
        std::vector<int> nums{ 4,5,6,7,0,1,2 };
        std::cout << " " << s.search(nums, 0);
    }
    {
        std::vector<int> nums{ 6,7,0,1,2,4,5 };
        std::cout << " " << s.search(nums, 0);
    }
    {
        std::vector<int> nums{ 4,5,6,7,0,1,2 };
        std::cout << " " << s.search(nums, 3);
    }
    {
        std::vector<int> nums{ 1 };
        std::cout << " " << s.search(nums, 0);
    }
    {
        std::vector<int> nums{ 1,3 };
        std::cout << " " << s.search(nums, 3);
    }

    return 0;
}