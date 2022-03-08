class Solution {
   
    
public:
    bool canPermutePalindrome(string s) {
        char     cmap[255] = {0,};
        for ( auto c : s ) {  cmap[c] ++;  }
        
        bool haveOne = false;
        for ( int i = 0 ; i < 255 ; ++i )
        {
            if ( cmap[i] == 0 ) continue;
            if ( s.size()%2 == 0 )
            {
                if( cmap[i]%2 )
                     return false;
            }
            else 
            {
                if( cmap[i]%2 )
                {
                    if ( haveOne )
                        return false;
                    haveOne = true;    
                }
            }
        }
        return true;
    }
};