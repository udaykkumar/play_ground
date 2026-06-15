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
