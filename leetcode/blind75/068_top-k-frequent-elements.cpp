

/**
 *
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        
        typedef int freq_t  ;
        typedef int value_t ;

        /// This following code generates a value -> frequency map
        std::unordered_map< value_t, std::pair< freq_t , value_t >  > squeeze;
        for ( auto n : nums ) {
        	if ( squeeze.find(n) != squeeze.end() ) {
        		squeeze[n].first ++;
        	} else  {
        		squeeze[n] = std::make_pair(1,n);
        		
        	}
        }
        


        /// what we do now is declare a priority Queue to store freq, value object 
        auto cmp = [] ( const std::pair< freq_t, value_t> &p1, const std::pair< freq_t, value_t> &p2 ) {
	        	return p1.first < p2.first;
	        };

		std::priority_queue< std::pair< freq_t, value_t >, std::vector< std::pair<freq_t, value_t> >,  decltype(cmp) >  pq(cmp);
         
        for ( auto kvp : squeeze ) {
        	pq.push(kvp.second);
        }

        std::vector<int> res;
        int i = 0;
        while ( (pq.size() > 0) and (i < k)) {
        	auto top = pq.top();
        	pq.pop();
        	++i;
        	//std::cout << top.first << " " << top.second << "\n";
        	res.emplace_back(top.second);
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    
    {
    	Solution s;
    	std::vector<int> nums{1,1,1,2,2,3};
    	auto res = s.topKFrequent(nums, 2);
    	for ( auto r : res ) {
    		std::cout << r << " ";
    	}
    	std::cout << "\n";
    }
    {
    	Solution s;
    	std::vector<int> nums{1};
    	auto res = s.topKFrequent(nums, 1);
    	for ( auto r : res ) {
    		std::cout << r << " ";
    	}
    	std::cout << "\n";
    }
    
    return 0;
}