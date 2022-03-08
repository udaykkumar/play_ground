// "helloThere", "ere"

int strStr(char* haystack, char* needle) {
    
    int needleLen = strlen(needle);
    int haystackLen = strlen(haystack);
    
    // Both Empty
    if( needleLen == 0 && haystackLen == 0 )
        return 0;
    // Needle Empty
    else if( needleLen == 0 )
        return 0;
    // Haystack Empty
    else if( haystackLen == 0 )
        return -1;
    // Needle is More than HayStack
    if( needleLen > haystackLen )
        return -1;
    
    char *hptr1 = NULL, *hptr2 = NULL, *nptr = NULL;
    
    hptr1 = haystack;
    for( ; *hptr1 ; hptr1 ++ ) {
        if( *hptr1 != *needle )
            continue;
        
        nptr = needle;
        hptr2 = hptr1;
        for( ; *nptr ; nptr ++, hptr2 ++  ){
            if( *nptr != *hptr2 )
                break;
        }
        
        if( *nptr == '\0' )
            return hptr1-haystack;
    }
    
    return -1;
}