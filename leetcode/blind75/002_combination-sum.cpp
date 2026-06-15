/**
 * 
 Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
 where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500

**/ 

#include <iostream>
#include <vector>

class Solution {

	void combinationSum( std::vector<int>& candidates, int target, int start,  std::vector< int > combination, std::vector< std::vector< int > > &res ) {

		if ( target == 0 ) {
			res.emplace_back(combination);
			return;
		}

		if ( target < 0 ) {
			return;
		} 

		for ( int i = start; i < int(candidates.size()); ++i ) {
			combination.emplace_back(candidates[i]);
			combinationSum( candidates, target - candidates[i], i, combination, res);
			combination.pop_back();
		}
	}

public:
    std::vector< std::vector<int>> combinationSum( std::vector<int>& candidates, int target) {
       	/// This need a bit of typing ..

       	///
       	///	The Idea is to that every entry in candidates needs to talk to other entry
       	/// starting for 0 - > candidated.length()
       	/// .. and that give rise to another combination
       	/// for instance for an example 
       	///			2, 3, 6, 7

        std::vector< std::vector< int > > res;
        std::vector< int > combination;
        if ( candidates.size() == 0 ) return res;


       	combinationSum( candidates, target, 0, combination, res);

        return res;
    }
};

int main(int argc, char const *argv[])
{
	{
		Solution s;
		std::vector< int > candidates{2,3,6,7};
		auto res = s.combinationSum(candidates, 7);
		for ( auto r : res ) {
			std::cout << " { ";
			for ( auto ri : r ) {
				std::cout << ri << " ";
			}
			std::cout << " } ";
		}
		std::cout <<"\n";
	}
	return 0;
}