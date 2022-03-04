

/**
 *
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
Accepted
609,499
Submissions
1,257,131

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set< int > journal( nums.begin(), nums.end());
        
        int longest = 0;
        for ( auto n : nums ) {
            if( journal.count(n) > 0 ) {
                journal.erase(n);
                int s = n-1;
                for ( ; journal.count(s) > 0 ; -- s) {
                    journal.erase(s);
                }
                int e = n+1;
                for ( ; journal.count(e) > 0 ; ++ e) {
                    journal.erase(e);
                }
                
                longest = std::max ( e - s -1, longest );
            }
        }
        
        return longest;
        
    }
};

int main(int argc, char const *argv[]) {
    
    {
        Solution so;
        std::vector<int> nums{100,4,200,1,3,2};
        std::cout << " " << so.longestConsecutive(nums) << "\n";
    }
  
  	{
        Solution so;
        std::vector<int> nums{0,3,7,2,5,8,4,6,0,1};
        std::cout << " " << so.longestConsecutive(nums) << "\n";
    }

    return 0;
}