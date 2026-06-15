class Solution {
public:
    
    inline bool isSmall( char x )
    {
        return 'a' <= x && x <= 'z';
    }
    
    inline bool isCaps( char x)
    {
        return 'A' <= x && x <= 'Z';
    }
    
    bool detectCapitalUse(string word) {
        
        if( word.length() <= 0 )
            return false;
        
        if( word.length() < 2 )
            return true;
        
        if( isCaps( word.at(0)) && isCaps( word.at(1)) )
        {
            for( int c : word )
            {
                if ( !isCaps(c))
                    return false;
            }
        }
        else 
        {
            for( size_t i = 1; i < word.size() ; ++i )
            {
                if ( ! isSmall(word.at(i)) )
                    return false;
            }
        }
        return true;
    }
};