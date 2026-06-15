
char* longestPalindrome(char* s)
{
    int maxLength = 1;
    int len = strlen(s);
    int start = 0;
    
    int low = 0, high = 0;
    
    for( int i = 1; i < len; i ++ )
    {
        
        low  = i - 1;
        high = i;
        
        while( low >= 0 && high < len && s[low] == s[high])
        {
            if( high - low + 1 > maxLength )
            {
                start = low;
                maxLength = high - low + 1;
            }
            
            low --; 
            high ++;
        }
        
        
        low  = i - 1;
        high = i + 1;
        
        
        while( low >= 0 && high < len && s[low] == s[high])
        {
            if( high - low + 1 > maxLength )
            {
                start = low;
                maxLength = high - low + 1;
            }
            
            low --; 
            high ++;
        }
    }
    
    char *b = malloc(maxLength+1);
    int j = 0 , n = start + maxLength ;
    for( int i = start; i < n ; i ++ )
        b[j ++] = s[i];
    
    b[j] = '\0';
    
    return b;
    
}
