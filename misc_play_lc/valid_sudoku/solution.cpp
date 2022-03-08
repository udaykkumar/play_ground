class Solution {
    
    /**
        00 01 02
        10 11 12
        20 21 22
        
          i,j  i,j+1    i,j+2
        i+1,j i+1,j+1 i+1,j+2
        i+2,j i+2,j+1 i+2,j+2
   
    **/
    
    
public:
    
    bool duplicate_exists_in_row(vector<vector<char>>& board, int i, char v)
    {
        
        for ( int j = 0 ; j < 9 ; ++j )
            if( board[i][j] == v )
                return true;
        return false;
    }
    
    bool duplicate_exists_in_col(vector<vector<char>>& board, int j, char v)
    {
        
        for ( int i = 0 ; i < 9 ; ++i )
            if( board[i][j] == v )
               return true;
        return false;
    }
    
    

    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        std::vector< std::vector<int> > squares = {
            {0,0}, {0,3}, {0,6},
            {3,0}, {3,3}, {3,6},
            {6,0}, {6,3}, {6,6}
        };
        
        std::set<char> nums = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for ( int x = 0 ; x < 9; x ++ )
        {
            for ( int y = 0; y < 9; y ++ )
            {
                if ( board[x][y] == '.')
                    continue;
                  
                char v = board[x][y];
                nums.erase(v);
                    
                for ( auto square : squares )
                {
                    int r = square[0], c = square[1];
                    int occurances = 0;
                    for ( int i = r; i < r+3; i ++ )
                    {
                        for ( int j = c ; j < c+3; j ++ )
                        {
                            if ( board[i][j] == v)
                            {
                                board[i][j] = '.';
                                occurances ++;
                                if (duplicate_exists_in_col( board, j, v ) or 
                                    duplicate_exists_in_row( board, i, v) )
                                    return false;
                            }
                       }
                    }
                
                    if (occurances > 1 )
                        return false;
                }
                
                if (nums.empty())
                    return true;
            }
        }
        
        
        return true;
           
    }
};