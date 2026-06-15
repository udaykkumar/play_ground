class Solution {
public:
    // [0,1,0,3,12]
    // [1,3,12]
    void moveZeroes(vector<int>& nums) {
        size_t hole = 0;
        for ( size_t i = 0 ; i < nums.size(); i ++ )
            if ( nums[i] )
               std::swap( nums[hole++], nums[i]);
        
        while( hole < nums.size() )
            nums[hole++] = 0;
            
    }
};