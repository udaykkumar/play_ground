

/**
 *

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100


 **/

#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {

	int R;
	int C;
	std::vector< std::vector< bool > > visited_;

	void make_visit_journal( ) {
		for ( int r = 0 ; r < R ; ++r ) {
			std::vector< bool > col;
			for ( int c = 0 ; c < C ; ++c ) {
				col.emplace_back(false);
			}
			visited_.emplace_back(col);
		}
	}
	

	bool visited( int r, int c ) {
		return visited_[r][c];
	}

	void visit( int r, int c ) {
		visited_[r][c] = true;
	}

	bool within_limits(int r, int c) {
		return r >= 0 and r < R and c >= 0 and c < C;
	}

public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    	/// Handle the obvious base cases
    	std::vector<int> so;
    	if ( matrix.size() == 0 ) return so;

    	/// R and C we need them everywhere
        R = matrix.size();
        C = matrix[0].size();

        /// make a visitor list 
		make_visit_journal();

		/// Maximum timed we'l 
        const int cells = R * C ;
       	for ( int  i = 0, r = 0, c = 0 ; i < cells;  ) {

        	/// Move right
        	for( ; within_limits(r,c) and not visited(r,c) ; ++c  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}

        	/// Get to start point for going down
        	c -= 1;
        	r += 1;

        	/// Move down
        	for( ; within_limits(r,c) and not visited(r,c) ; ++r  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}
        	/// Get to start point for going left
        	r -= 1;
        	c -= 1;

        	/// Move left
        	for( ; within_limits(r,c) and not visited(r,c) ; --c  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}
        	/// Get to start point for going up
        	c += 1;
        	r -= 1;

        	/// Move up 
        	for( ; within_limits(r,c) and not visited(r,c) ; --r  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}

        	/// Get to start point for going right
        	r += 1;
        	c += 1;
        } 

        return so;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    {
        std::vector<std::vector<int>>  matrix{  {4,5,6,7,0,1,2}, 
        										{4,5,6,7,0,1,2}, 
        										{4,5,6,7,0,1,2}, 
        										{4,5,6,7,0,1,2}, 
        										{4,5,6,7,0,1,2} };
        for ( auto r : matrix ) {
        	for ( auto c : r ) {
        		std::cout << c << " ";
        	}
        	std::cout << std::endl;
        }
        auto so =  s.spiralOrder(matrix);
        for ( auto r : so ) {
        	std::cout << r << " ";
        }
        std::cout << "\n";
        

    }
    return 0;
}