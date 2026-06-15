

/**
 *

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
Accepted
628,948
Submissions
1,315,939

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {

	const int MagicSign = 555;
	int R_;
	int C_;


	void fill_col(int r, int c, std::vector<std::vector<int>>& matrix) {

		for ( int i = 0; i < R_; ++i ) { 
			if( matrix[i][c] != 0 )
				matrix[i][c] = MagicSign; 
		}
	}

	void fill_row(int r, int c, std::vector<std::vector<int>>& matrix) {
		for ( int i = 0; i < C_; ++i ) { 
			if( matrix[r][i] != 0 ) 
				matrix[r][i] = MagicSign; 
		}
	}


public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
    	if ( matrix.size() == 0 ) return;

    	R_ = matrix.size();
    	C_ = matrix[0].size();
        for ( int r = 0 ; r < R_; ++r ) {
        	for (int c = 0; c < C_; ++c) {
        		if ( matrix[r][c] == 0 ) {
        			fill_col(r,c,matrix);
        			fill_row(r,c,matrix);
        		}
        	}
        }

        for ( auto &r : matrix ) {
        	for ( auto &c : r ) {
        		if ( c == MagicSign ) c = 0;
        	}
        }
        return ;
    }
};

int main(int argc, char const *argv[]) {
    
    {
        Solution s;
       	std::vector<std::vector<int>>  matrix{  {1,1,1}, 
        										{1,0,1},
        										{1,1,1} };
        for ( auto r : matrix ) {
        	for ( auto c : r ) {
        		std::cout << c << " ";
        	}
        	std::cout << std::endl;
        }
        std::cout << "\n";
        s.setZeroes(matrix);
        for ( auto r : matrix ) {
        	for ( auto c : r ) {
        		std::cout << c << " ";
        	}
        	std::cout << std::endl;
        }
        std::cout << "\n";
    }

    {
        Solution s;
       	std::vector<std::vector<int>>  matrix{  {0,1,2,0}, 
        										{3,4,5,6},
        										{9,7,8,2} };
        for ( auto r : matrix ) {
        	for ( auto c : r ) {
        		std::cout << c << " ";
        	}
        	std::cout << std::endl;
        }
        std::cout << "\n";
        s.setZeroes(matrix);
        for ( auto r : matrix ) {
        	for ( auto c : r ) {
        		std::cout << c << " ";
        	}
        	std::cout << std::endl;
        }
        std::cout << "\n";
    }

    return 0;
}