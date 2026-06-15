class Solution {

	const int NeedChange = 555;
	int R_;
	int C_;

	void fill_col(int r, int c, std::vector<std::vector<int>>& matrix) {

		for ( int i = 0; i < R_; ++i ) { 
			if( matrix[i][c] != 0 )
				matrix[i][c] = NeedChange; 
		}
	}

	void fill_row(int r, int c, std::vector<std::vector<int>>& matrix) {
		for ( int i = 0; i < C_; ++i ) { 
			if( matrix[r][i] != 0 ) 
				matrix[r][i] = NeedChange; 
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
        		if ( c == NeedChange ) c = 0;
        	}
        }
        return ;
    }
};