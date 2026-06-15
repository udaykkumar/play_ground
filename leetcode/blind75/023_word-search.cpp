

/**
 *
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

 

Example 1:


Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = 'ABCCED'
Output: true
Example 2:


Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = 'SEE'
Output: true
Example 3:


Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = 'ABCB'
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <set>

class Solution {
	
public:
    bool exist(std::vector< std::vector<char> >& board, std::string word) {

    	if ( board.size() == 0 ) return false;
    	if ( word.size()  == 0 ) return true;


    	std::function< bool(int, int, std::string &) > cmp = [&]( int r, int c, std::string &w) -> bool {

    		/// If there is no word means we are done .. its a success
			if ( w.size() == 0 ) return true;
			
    		/// if we  are out of bounds or 
    		/// the first character in w is not equal is char at boards r,c cordinated 
    		/// its a failure
    		if ( r < 0 or r >= int(board.size()) or c < 0 or c >= int(board[0].size()) or w[0] != board[r][c] ) 
    			return false;

    		/// Mark this as visited .. 
    		board[r][c] = '?';

    		/// calculate substring of w .. and recurse
    		auto wsub = w.substr(1);
    		bool ret = cmp( r+1,    c, wsub ) ||
    					cmp( r-1,   c, wsub ) ||
    					cmp( r  , c+1, wsub ) ||
    					cmp( r  , c-1, wsub );
    		

    		/// revert it to original
    		board[r][c] = w[0];

    		/// done if its Yes its a Yes else a no
    		return ret;
    	};


    	
    	for ( int r = 0 ; r < int(board.size()); ++r ) {
    		for ( int c = 0 ; c < int(board[0].size()); ++c ) {
    			if ( cmp(r,c,word) )
    				return true;
    		}
    	}

        return false;
    }
};

int main(int argc, char const *argv[]) {
    
    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{ {'A','B','C','E'},
    											{'S','F','E','S'},
    											{'A','D','E','E'}};


        std::string word = "ABCESEEEFS";
        
        if ( not s.exist(matrix,word) ) {
        	std::cout << "Failed Expected true \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
        else{
        	std::cout << "Pass " << word << " \n" ;
        }
        
    }
    //exit(0);
    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{	{'C','A','A'},
    											{'A','A','A'},
    											{'B','C','D'}};


        std::string word = "AAB";
        if ( not s.exist(matrix,word) ) {
        	std::cout << "Failed Expected true \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
        else{
        	std::cout << "Pass " << word << " \n" ;
        }
    }
    
    

    

    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{  {'A','A','A','A','A','A'},
    											 {'A','A','A','A','A','A'},
    											 {'A','A','A','A','A','A'},
    											 {'A','A','A','A','A','A'},
    											 {'A','A','A','A','A','A'},
    											 {'A','A','A','A','A','A'}
    											};

        std::string word = "AAAAAAAAAAAAAAB";
        if (  s.exist(matrix,word) ) {
        	std::cout << "Failed Expected false \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
        else{
        	std::cout << "Pass " << word << " \n" ;
        }
    }

    

    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{  {'A','B','C','E'},
												 {'S','F','C','S'},
												 {'A','D','E','E'}};
        std::string word = "ABCCED";
        if ( not s.exist(matrix,word) ) {
        	std::cout << "Failed Expected true \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
        else{
        	std::cout << "Pass \n" ;
        }
    }

    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{  {'A','B','C','E'},
												{'S','F','C','S'},
												{'A','D','E','E'}}; 
        std::string word = "SEE";
        if ( not s.exist(matrix,word) ) {
        	std::cout << "Failed Expected true \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
        else{
        	std::cout << "Pass \n" ;
        }
    }

    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{  {'A','B','C','E'},
												{'S','F','C','S'},
												{'A','D','E','E'}};
        std::string word = "ABCB";
        if ( s.exist(matrix,word) ) {
        	std::cout << "Failed Expected false \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
    }

    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{  {'A'}};
        std::string word = "A";
        if ( not s.exist(matrix,word) ) {
        	std::cout << "Failed Expected true \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
        else{
        	std::cout << "Pass \n" ;
        }
    }

    {
    	Solution s;
    	std::vector<std::vector<char>>  matrix{  {'A', 'B'},
    											 {'C', 'D'}};
	     std::string word = "ABDC";
        if ( not s.exist(matrix,word) ) {
        	std::cout << "Failed Expected true \n";
        	for ( auto r : matrix ) {
        		for ( auto c : r ) {
        			std::cout << c << ' ';
        		}
        		std::cout << std::endl;
        	}
        	std::cout << "\nword " << word << " "  << s.exist(matrix,word) << "\n";
        }
        else{
        	std::cout << "Pass \n" ;
        }
    }

    
    
    return 0;
}