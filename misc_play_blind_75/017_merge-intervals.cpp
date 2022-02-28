

/**
 *

Given an array of intervals where intervals{i} = {starti, endi}, 
merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = {{1,3},{2,6},{8,10},{15,18}}
Output: {{1,6},{8,10},{15,18}}
Explanation: Since intervals {1,3} and {2,6} overlaps, merge them into {1,6}.
Example 2:

Input: intervals = {{1,4},{4,5}}
Output: {{1,5}}
Explanation: Intervals {1,4} and {4,5} are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals{i}.length == 2
0 <= starti <= endi <= 104
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector < std::vector<int>> merge( std::vector< std::vector<int> >& intervals) {
        
        const size_t start = 0;
        const size_t end   = 1;

        std::vector < std::vector<int>> res;
            if ( int(intervals.size()) == 0 ) {
            	return res;
            }
        	
        	std::sort ( intervals.begin(), intervals.end(), []( const std::vector<int> &x, const std::vector<int> &y ) {
        		return x[0] < y[0];
        	});


        	res.emplace_back( intervals[0] );

        	for ( int i = 1 ; i < int(intervals.size()) ; ++i ) {
        		if ( intervals[i][start] <= res[res.size()-1][end] ) {
        			res[ res.size() - 1 ][end] = std::max ( intervals[i][end], res[res.size()-1][end]);
        		} else {
        			res.emplace_back(intervals[i]);
        		}
        	}
        return res;
    }
};

int main(int argc, char const *argv[]) {
    
    {
        Solution s;
        std::vector< std::vector<int> >  intervals{{1,3},{2,6},{8,10},{15,18}};
        auto mi = s.merge(intervals);
        for ( auto i : mi ) {
        	std::cout << "{ ";
        	for ( auto iv : i ) { std::cout << iv << " "; }
        	std::cout << " }";
        }
        std::cout << " \n";
    }

    {
        Solution s;
        std::vector< std::vector<int> >  intervals{{2,6},{8,10},{15,18},{1,3}};
        auto mi = s.merge(intervals);
        for ( auto i : mi ) {
        	std::cout << "{ ";
        	for ( auto iv : i ) { std::cout << iv << " "; }
        	std::cout << " }";
        }
        std::cout << " \n";
    }
    {
        Solution s;
        std::vector< std::vector<int> >  intervals{{1,4},{4,5}};
        auto mi = s.merge(intervals);
         for ( auto i : mi ) {
        	std::cout << "{ ";
        	for ( auto iv : i ) { std::cout << iv << " "; }
        	std::cout << " }";
        }
        std::cout << " \n";
    }
    {
        Solution s;
        std::vector< std::vector<int> >  intervals{{1,4},{2,3}};
        auto mi = s.merge(intervals);
         for ( auto i : mi ) {
        	std::cout << "{ ";
        	for ( auto iv : i ) { std::cout << iv << " "; }
        	std::cout << " }";
        }
        std::cout << " \n";
    }

    {
        Solution s;
        std::vector< std::vector<int> >  intervals{{2,3}, {4,5}, {6,7}, {8,9}, {1,10}};
        auto mi = s.merge(intervals);
         for ( auto i : mi ) {
        	std::cout << "{ ";
        	for ( auto iv : i ) { std::cout << iv << " "; }
        	std::cout << " }";
        }
        std::cout << " \n";
    }
    
    return 0;
}