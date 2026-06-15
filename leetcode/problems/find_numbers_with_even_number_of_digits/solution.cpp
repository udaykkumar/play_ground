class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int total = 0;
        for ( auto n : nums )
        {
            int d = 0;
            for ( ; n ; n /= 10)
                d++;
            if ( d%2 == 0 )
                total ++;
        }
        
        return total;
    }
};