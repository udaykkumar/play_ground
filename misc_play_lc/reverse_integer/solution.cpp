class Solution {
public:
    const long LOWER_LIMIT = -2147483648;
    const long UPPER_LIMIT = 2147483647;
    int reverse(int x) {
        long N = 0;
        for ( ; x ; x = x /10 ) {
            N = (N*10) + (x%10) ;
        }
        return ( N < LOWER_LIMIT || N > UPPER_LIMIT) ? 0 : N;
    }
};