int reverse(int x) {
    
    unsigned int INTMAX = 0;
    INTMAX = ((~INTMAX) & 0xFFFFFFFF)>>1;
    
    if(x == 0 )
        return 0;
    
    int mult = ( x < 0 ) ? -1 : 1;
    x *= mult;
    long rev = 0;
    while( x > 0 )
    {
        int r = x%10;
        rev = rev*10+r;
        x /= 10;
    }
    
    //printf("%d %u %d\n", rev, INTMAX, sizeof(rev));
    
    if( rev > INTMAX )
        return 0;
    
    int ret = ((int) rev) * mult;
    return (ret);
}