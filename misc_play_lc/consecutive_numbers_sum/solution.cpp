class Solution {
public:
    int consecutiveNumbersSum(int N) {

    /*
        n + n+1 = N

        n + n+1 + n+2 = 3n + 2(2+1)/2
        
        n + n+1 + n+2 + n+3 = 4n + 3(3+1)/2
        
        n + n+1 + n+2 + .. + n+i = (i+1)n + i(i+1)/2 => (i+1)[n+i/2];
        
        (i+1)n + i(i+1)/2 = N
        (i+1)n = N - ((i) * (i + 1) / 2 )
             n = N - ((i) * (i + 1) / 2 ) / (i+1)
             
        (i+1)[n+i/2] = N
        (n + i/2) = N / (i+1)
     */

    int count = 0;
        // x > 0 --> N/k - (k + 1)/2 > 0
        int upper_limit = (int)(sqrt(2 * N + 0.25) - 0.5);
        for (int k = 1; k <= upper_limit; ++k) {
            // x should be an integer
            if ((N - k * (k + 1) / 2) % k == 0)
                count++;
        }
        return count;
    }
};