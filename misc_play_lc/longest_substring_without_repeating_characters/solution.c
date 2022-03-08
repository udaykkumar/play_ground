int lengthOfLongestSubstring(char* s) {
    int longestSequnece = 0;
    
    for( ; *s ; s ++ ) {
        
        char alphabet[255] = {0};
        char *start = s, *end = s;
        int sequence = 0;
    
        for( ; *end && alphabet[(unsigned char)*end] == 0 ; end ++)
            alphabet[(unsigned char)*end] = 1 ;
            
        sequence = end - start;

        if( sequence > longestSequnece )
           longestSequnece = sequence;
    }
    
    return longestSequnece;

}