class Solution {
    
    int rows;
    int cols;
    int islands;    
    
    void dfs( vector< vector<char> > &grid, int r, int c )
    {
        // this is a case we encountered water or border
        if ( r < 0 || c < 0 || r >= rows || c >= cols || 
           grid[r][c] == '0' )
            return ;
        
        // Fill the land with Water
        grid[r][c] = '0';
        
        dfs( grid, r-1, c);
        dfs( grid, r+1, c);
        dfs( grid, r, c-1);
        dfs( grid, r, c+1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if ( grid.size() == 0 )
            return 0;
        
        rows = grid.size();
        cols = grid[0].size();
        islands = 0;    
   
        for ( int r = 0 ; r < rows; ++r )
        {
            for ( int c = 0 ; c < cols; ++c )
            {
                if ( grid[r][c] == '1' )
                {
                    ++islands;
                    dfs( grid, r, c);
                }
            }
        }
        
        return islands;
    }
};