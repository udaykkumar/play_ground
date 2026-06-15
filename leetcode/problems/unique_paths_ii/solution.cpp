class Solution {
    
    int rc;
    int cc;
    std::set< std::pair<int,int>> obs;
    
    int dfs(vector<vector<int>>& g, int r, int c)
    {
        if ( r < 0 || c < 0 || r >= rc || c >= cc )
            return 0;
        
        if ( obs.find( std::pair(r,c)) != obs.end() )
            return 0;
        
        if ( r == rc-1 && c == cc-1 )
            return 1;
        
        if ( g[r][c] )
            return g[r][c];
        
        int lc = dfs( g, r+1, c);
        int rc = dfs( g, r, c+1);
        
        g[r][c] = lc + rc;
        return g[r][c];
    }
    
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rc = obstacleGrid.size();
        cc = obstacleGrid[0].size();
        for ( int r = 0 ; r < rc ; ++r )
            for ( int c = 0; c < cc; ++c )
                if ( obstacleGrid[r][c] )
                    obs.insert( std::pair(r,c) );
                
        return dfs( obstacleGrid, 0, 0);
    }
};