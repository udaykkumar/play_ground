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