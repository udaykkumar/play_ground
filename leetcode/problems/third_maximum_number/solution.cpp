class Solution {
public:
    int thirdMax(vector<int>& v) {
        
        std::set s( v.begin(), v.end() );
        std::vector<int> nums(s.begin(), s.end());
        
        if ( nums.size() == 0 )
            return 0;
        
        if ( nums.size() == 1 )
            return nums[0];
        
        if ( nums.size() == 2 )
            return max( nums[0], nums[1] );
        
        make_heap( nums.begin(), nums.end() );
        
        pop_heap( nums.begin(), nums.end() );
        nums.pop_back();
        
        pop_heap( nums.begin(), nums.end() );
        nums.pop_back();
        
        return nums.front();
    }
};