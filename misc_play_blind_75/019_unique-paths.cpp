

/**
 *

There is a robot on an R_ x C_ grid. 
The robot is initially located at the top-left corner (r.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (r.e., grid[R_ - 1][C_ - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers R_ and C_, return the number of possible unique paths_ that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: R_ = 3, C_ = 7
Output: 28
Example 2:

Input: R_ = 3, C_ = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. R_ight -> Down -> Down
2. Down -> Down -> R_ight
3. Down -> R_ight -> Down
 

C_onstraints:

1 <= R_, C_ <= 100
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution {

	std::vector < std::vector< int > > visited_;
	int R_ ;
	int C_ ;

	void make_visit_journal() {
		visited_ = std::vector < std::vector< int > >(R_ , std::vector<int>( C_, 0) );
	}

	int seen( int r, int c ) {
		return visited_[r][c];
	}

	void see( int r, int c, int v ) {
		visited_[r][c] = v;
	}

	int peek( int r, int c ) {
		return visited_[r][c];
	}

	bool out_of_bounds(int r, int c) {
		return ( r >= R_ or c >= C_ or r < 0  or c < 0 );
	}

	bool at_target(int r, int c) {
		return ( r == R_-1 and c == C_-1 );
	}

	
	int explore(int r, int c) {
		/// we are beyond boundary
		if ( out_of_bounds(r, c) ) 
		 	return 0;	

		/// if we have not seen  
		if ( not seen(r,c) ) {

			/// if we are at the target
			if ( at_target(r,c) ) {
				/// its one path
				see(r, c, 1);
			} else {
				/// else its paths to right + paths to down
				see( r, c, explore(r,c+1) + explore(r+1,c));
			}
		}

		/// send back what we saw
		return peek(r,c);
	}

public:
    int uniquePaths(int r, int c) {
		R_ = r;
		C_ = c; 
		make_visit_journal();
		return explore(0,0);
	}
};


int main(int argc, char const *argv[]) {
    
    {
        Solution s;
       	std::cout << s.uniquePaths(3,7) << std::endl;
    }

    {
        Solution s;
       	std::cout << s.uniquePaths(3,2) << std::endl;
    }
    
    return 0;
}