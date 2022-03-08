class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        int s = 0;
        for( int i = 0; i < r ; ++i ) {
            for ( int j = 0 ; j < c; ++j ) {
                if ( m[i][j] == 0 )
                     continue;
                
                if ( i == 0 or j == 0 )
                {
                    s += 1;
                    continue;
                }
                
                m[i][j] += std::min(m[i-1][j-1], std::min( m[i-1][j], m[i][j-1]));
                s += m[i][j];
            }
        }
        return s;
    }
};