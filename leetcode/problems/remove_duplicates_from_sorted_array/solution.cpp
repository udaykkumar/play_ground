class Solution {
public:
int removeDuplicates(std::vector<int>& nums)
        {
            if( nums.size() == 0 )
                return 0;

            int compare_to = 0;
            for (int i = 1; i < nums.size(); ++i)
            {
                if( nums[i] != nums[compare_to] )
                {
                    compare_to ++;
                    nums[compare_to] = nums[i];
                }
            }

            return compare_to + 1;
        }
};