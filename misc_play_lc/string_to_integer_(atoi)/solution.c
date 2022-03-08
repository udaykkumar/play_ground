/*

int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
    */


int myAtoi(char* s) 
{
    
    int value = 0;
    int signbit = 1;
    
    // Has to be non null
    if(s) 
    {
        // Trim Leading Spaces
        for( ; *s == ' '; s ++ ) ;
        
        // if any of the first character is +/- skip it
        // record the sign though
        if( *s == '-')
        {
            signbit = -1;
            s ++;
        }
        else if ( *s == '+' )
        {
            signbit = 1;
            s++;
        }
        
        // Try Calculating the number now
        int n = strlen(s);
        for(int i = 0 ; i < n ; i ++ )
        {
            // This has to be a number
            if( s[i]  < '0' || s[i] > '9' )
              goto out;
                
            
            if (value >  INT_MAX / 10 || (value == INT_MAX / 10 && s[i] - '0' > 7))
            {
                if( signbit == 1 )
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            
            // calculate value
            value = value * 10 + ( s[i] - '0' ) ;
            printf("%d\n", value );
        }
            
    }
    
out:
    return signbit * value ;
}