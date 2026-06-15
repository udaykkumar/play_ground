class Solution {
    
    std::vector< std::vector< int > > permutations_;
    void permute( vector<int> & nums, int start)
    {
        if ( start == nums.size()-1 )
        {
            for ( auto n : nums )
                std::cout << n << " " ;
            std::cout << "\n";
            permutations_.push_back(nums);
            return;
        }
        
        for ( int i = start ; i < nums.size() ; ++i ) 
        {
            std::swap( nums[i], nums[start]);
            permute( nums, start + 1 );
            std::swap( nums[i], nums[start]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0 );
        return permutations_;
    }
};