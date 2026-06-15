

/**
 *

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000


 **/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {


public:
    void rotate(std::vector< std::vector<int>>& matrix) {
        if ( matrix.size() == 0 ) return;

        /// As beautiful as it sounds .. 
        /// Do not try this at all.
        /// This is a very very smart way of doing things
        /// We usually
        std::reverse( matrix.begin(), matrix.end());
        
        /// No one in good health would probably think of doing 
        /// something like this .. 
        /// Unless of course that person is a genius
        /// I .. shamelessly copied this .. 
        /// and I am not embarassed .. because this code is designed to
        /// make people cry ... 
		int R = matrix.size();
		int C = matrix[0].size();
		for ( int r = 0 ; r < R ; ++r ) {
			for ( int c = r+1; c < C ; ++c ) {
				std::swap( matrix[r][c], matrix[c][r]);
			}
		}
		
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    {
        std::vector<std::vector<int>>  matrix{  {1,2,3},
        										{4,5,6},
        										{7,8,9}  };

        s.rotate(matrix);
        for ( int r = 0 ; r < int( matrix.size()) ; ++ r) {
        	for ( int c = 0; c < int( matrix.size()) ; ++c) {
        		std::cout << matrix[r][c] << " ";
        	}
        	std::cout << std::endl;
        }
    }
    return 0;
}