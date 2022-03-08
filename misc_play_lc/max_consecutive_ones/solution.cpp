class Solution {
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int ones = 0;
        for( auto i : nums )
        {
            ones = ( i != 1) ? 0 : ( ++ones );
            if ( max_ones < ones )
                max_ones = ones;
        }

        return max_ones;
    }
};