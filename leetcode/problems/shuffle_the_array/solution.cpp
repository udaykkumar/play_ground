class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size(),0);
        int idx = 0;
        for( int i = 0, j = n; i < n && j < nums.size(); i++, j ++ )
        {
            res[idx++] = nums[i];
            res[idx++] = nums[j];
        }
        return res;
    }
};