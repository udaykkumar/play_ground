class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        size_t sum = 0;
        for ( auto x : nums )
            sum += x;
        std::sort( nums.begin(), nums.end(), greater() );
        
        std::vector<int> res;
        size_t nsum = 0;
        for( auto n : nums )
        {
            if ( sum >= nsum )
            {
                sum -= n;
                nsum += n;
                res.push_back(n);
            }
            else
            {
                break;
            }
        }
        
        return res;
    }
};