class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if( target == nums[i] )
                return i;
            else if( nums[i] < target  )
                index ++;
            else
                return index;
        }
        return index;
    }
};