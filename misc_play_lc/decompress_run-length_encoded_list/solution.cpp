class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        std::vector<int> res;
        for ( int i = 0 ; i < nums.size() ; i += 2 )
        {
            int f = nums[i];
            int v = nums[i+1];
            
            for ( int x = 0; x < f ; ++x )
                res.emplace_back(v);
            
        }
        
        return res;
    }
};