class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle.length() == 0 )
            return 0;

        if( needle.length() > haystack.length() )
            return -1;

        for( int pos = 0 ; pos < (haystack.length() - needle.length() + 1)  ; pos ++)
            if( needle[0] == haystack[pos] && 
                haystack.compare( pos, needle.length(), needle) == 0 )
                return pos;
      
        return -1;   
    }
};