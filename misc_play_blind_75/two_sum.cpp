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

    std::unordered_map< int, size_t > vtoi_;

    void make_vtoi( const std::vector<int> &nums ) {
        size_t index = 0;
        for ( auto n : nums  ) {
            vtoi_[n] = index;
            ++index;
        }
    }

    bool exists_in_map( const int v ) const {
        return vtoi_.find(v) != vtoi_.end();
    }

    size_t index_of( const int v ) {
        return vtoi_[v];
    }

public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        
        /// Create a map of value to index
        make_vtoi(nums);

        /// for each element in list
        for ( size_t i = 0 ; i < nums.size() ; ++i ) {

            /// we look for target - current element
            int look_for { target - nums.at(i) };

            /// if exists .. 
            if ( exists_in_map(look_for) ) {

                auto idx { index_of(look_for) };
                /// Make sure its not looking at it-self
                if ( idx != i ) {

                    /// all well means we are done
                    return { (int)idx , (int)i };
                }
            }
        }

        return { -1, -1 } ;
    }
};

int main(int argc, char const *argv[]) {
    std::cout << " hello two_sum \n";

    Solution s;
    {
        std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8};
        auto res = s.twoSum(nums, 15);
        std::cout << "{ " << res[0] << " , " << res[1] << " }\n";
    }

    return 0;
}