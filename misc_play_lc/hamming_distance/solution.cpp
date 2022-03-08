class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int o = (x ^ y);
        int bits = 0;
        for ( int i = 0 ; i <= 31; i ++ )
        {
            if ( (1 << i) & o )
                bits ++;
        }
        return bits;
    }
};