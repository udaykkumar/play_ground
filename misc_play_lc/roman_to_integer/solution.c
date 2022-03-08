
int getVal(char c)
{
    switch (c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}


int romanToInt(char* s) 
{
    if( s == NULL )
        return 0;
    
    int n   = strlen(s);
    int res = getVal(s[n-1]);
    
    for( int  i = n -2 ; i >= 0 ; i --  )
    {
        int v1 = getVal(s[i]);
        int v2 = getVal(s[i+1]);
        
        if( v1 >= v2 )
        {
            res += v1;
        }
        else
        {
            res -= v1;
        }
    }
    
    return res;
}