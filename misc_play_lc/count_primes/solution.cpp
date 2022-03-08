class Solution {
public:
    int countPrimes(int n) {
        char *seive = new char[n+1];
        memset( seive, 0x00, n+1 );
        int c = 0;
        for ( int i = 2 ; i < n ; i ++ )
        {
            if ( seive[i] == 1 )
                continue;
            c++;
            for ( int j = i + i ; j < n ; j += i )
                seive[j] = 1;
        }
        return c;
    }
};