

char* longestCommonPrefix(char** strs, int strsSize) {
    
   
    char *retString = malloc(1024);
         *retString = '\0';
    memset(retString, 0x00, 1024);
    // [] <- this case
    if( strs == NULL || *strs == NULL )
    {
        return retString;
    }
    
    // Go Column Wise search
    int index = 0;
    for(  ;  strs[0][index]  != '\0' ; ) 
    {
        
        char c = strs[0][index];
        for( int i = 0 ; i < strsSize ; i ++ ) // for a Given String
        {
            if( !strs[i][index] )    // End of String
            {
                retString[index] = '\0';
                return retString; // nothing much to do
            }
            else
            {
                if( c != strs[i][index] )
                {
                    retString[index] = '\0';
                    return retString;
                }
            }
        }
        
        retString[index ++] = c;
    }
    
    
    return retString;
}