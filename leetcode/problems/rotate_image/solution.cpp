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