class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort( nums.begin(), nums.end() );
        for( std::size_t i = 0 ;
                i < nums.size() -1 ;  )
        {
            if( nums[i] == nums[i+1] )
                i += 2;
            else
                return nums[i];
        }
        
        return nums[ nums.size()-1];
    }
};