class Solution {
public:
    char findTheDifference(string s, string t) {
        int cmap[26] = {0,};
        
        int i = 0 ;
        for ( ; i < s.size() ; ++i ) {
            cmap [ t[i] - 'a' ] += 1;
            cmap [ s[i] - 'a' ] -= 1;
        }
        cmap [ t[ s.size() ] - 'a' ] += 1;
        
        
        for ( int x = 0 ; x < 26 ; x ++ ) {
            if ( cmap[x] != 0 )
                return (char) (x + 'a');
        }
        
        return 0;
    }
};