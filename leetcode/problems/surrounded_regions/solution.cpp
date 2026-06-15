class Solution {
    
    int ROW ;
    int COL ;
    
    bool withinBorder( int i, int j )
    {
        if ( i < 0 or j < 0 or i >= ROW or j >= COL )
            return false;
        return true;
    }
    
    bool atBorder( int i, int j )
    {
        return i == 0 or i == ROW-1  or j == 0 or j == COL-1;
    }
    
    void capture( std::vector< std::vector< char > > &b, int i, int j )
    {
        if ( withinBorder(i,j) == false )
            return;
        
        if ( b[i][j] != 'O' )
            return ;
       
        
        b[i][j] = 'Z';
        
        capture( b, i+1, j) ;
        capture( b, i-1, j) ;
        capture( b, i, j+1) ;
        capture( b, i, j-1) ;
                
        
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        // calculate ROW and COL values 
        // for given board
        ROW = -1;
        COL = -1;
        if ( board.size() > 0 )
        {
            ROW = board.size();
            if ( ROW > 0 )
            {
                COL = board[0].size();
            }
        }
        
        // Do initial sanity 
        if ( ROW < 0 or COL < 0 )
            return;
        
        
        // We Travel Through the boundary
        // Left most and Right Most
        for ( int i = 0 ; i < ROW ; i ++ )
        {
           capture(board, i, 0);
           capture(board, i, COL-1);
        }
        
        // Top most and Bottom most
        for ( int j = 0 ; j < COL ; j ++ )
        {
            capture(board, 0, j);
            capture(board, ROW-1, j);
        }
        
        
        for ( int i = 0 ; i < ROW ; i ++ )
        {
            for ( int j = 0 ; j < COL ; j ++ )
            {
               if ( board[i][j] == 'Z' )
                   board[i][j] = 'O';
               else if( board[i][j] =='O')
                   board[i][j] = 'X';
            }
        }
    }
};