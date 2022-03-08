


/*

    |                                   * an
    |                                   | 
    * a0            * a3                |
    |               |                   |
    |   a1          |                   |
    |  *     a2                         |
    |  |    *       |                   |
    |  |    |       |                   |
    |  |    |       |   .  .  .  . .    |
    |  |    |       |                   |
    +--+----+-------+-------------------+--------------------
    0  1    2       3                   n 


    A(ai,aj) = |j-i| * |aj-ai| { |i-j| == width , |ai - aj| == Height
    
*/

int max( int a, int b)
{
    return ( a > b ) ? a : b ;
}

int min( int a, int b)
{
    return ( a > b ) ? b : a;
}

int caclulateArea( int *a, int i, int j)
{
    return min(a[i],a[j]) * (j-i);
}


int maxArea(int* height, int heightSize) 
{
    
    int i = 0;
    int n = heightSize - 1;
    int maxarea = 0;
    
    while( i <= n )
    {
        maxarea = max( maxarea, caclulateArea(height, i, n));
        if( height[i] < height[n])
            i ++;
        else
            n --;
    }

    return maxarea;
}