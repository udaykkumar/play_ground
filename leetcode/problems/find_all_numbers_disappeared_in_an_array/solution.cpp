class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int nv[nums.size()+1];
        
        for ( int i = 0 ; i < nums.size()+1;  ++i )
            nv[i] = 0;
        
        for ( auto n : nums )
            nv[n] += 1;
        
        for ( size_t i = 1; i < nums.size()+1; ++i )
            if ( nv[i] == 0 )
                res.push_back(i);
        return res;
    }
};