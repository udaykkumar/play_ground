
int climbStairs(int n) {
   
    if( n == 1 )
        return 1;
    else if ( n == 2 )
        return 2;
    
    int f1 = 1, f2 = 2, f = 0 , i = 3;
    
    while ( i <= n )
    {
        f = f1 + f2;
        f1 = f2; 
        f2 = f;
        i ++;
    }
    
    return f;
}