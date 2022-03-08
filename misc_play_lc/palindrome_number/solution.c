
bool isPalindrome(int x) {
    if( x < 0 )
        return false;
    
    if( x > 0 && x < 10 )
        return true;
    
    
    int l = 0;
    int n = x;
    for( ; x ; x /= 10 )
        l ++;
        
    int mid = 0;
    if( l%2 == 0 )
        mid = l/2;
    else
        mid = (l/2) + 1;
    
    x = n;
    
    
    int rev = 0;
    for ( int i = l ; i > mid ;  i -- , x /= 10 )
        rev = rev*10 + x%10;
    
    
    //printf("%d %d %d", rev, l, x );

    if( l%2 == 0 )
        return rev == x;
    else
        return rev == x/10;
    
}