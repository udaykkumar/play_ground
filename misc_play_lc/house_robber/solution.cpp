class Solution {
    
   
    
public:
    int rob(vector<int>& nums) {
        int even_sum = 0;
        int odd_sum = 0;
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            
            if ( i%2 == 0 ) {
                even_sum =  std::max( odd_sum, even_sum + nums[i] );
            } else {
                odd_sum =  std::max( odd_sum + nums[i], even_sum );
            }
        }
        return std::max( odd_sum, even_sum );
    }
    
};