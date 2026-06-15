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

    	std::vector<int> so;
    	if ( matrix.size() == 0 ) return so;

        R = matrix.size();
        C = matrix[0].size();
		make_visit_journal();

        int cells = R * C ;
        int i = 0, r = 0, c = 0;


        while ( i < cells ) {

        	/// Move right
        	for( ; within_limits(r,c) and not visited(r,c) ; ++c  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}

        	c -= 1;
        	r += 1;

        	/// Move down
        	for( ; within_limits(r,c) and not visited(r,c) ; ++r  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}
        	r -= 1;
        	c -= 1;

        	/// Move left
        	for( ; within_limits(r,c) and not visited(r,c) ; --c  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}

        	c += 1;
        	r -= 1;

        	/// Move up 
        	for( ; within_limits(r,c) and not visited(r,c) ; --r  ) {
        		visit(r,c); so.emplace_back(matrix[r][c]); ++i;
        	}

        	r += 1;
        	c += 1;
        } 

        return so;
    }
};
