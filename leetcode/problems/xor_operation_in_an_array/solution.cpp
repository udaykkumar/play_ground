class Solution {
public:
    int xorOperation(int n, int start) {
        
        if ( n <= 0 )
            return 0;
        
        int a[n];
        for ( int i = 0; i < n ; ++i )
        {
            a[i] = start + 2*i;
        }
        
        int res = a[0];
        for ( int i = 1 ; i < n ; ++i )
            res ^= a[i];
        
        return res;
    }
};