#include <LC_E_0008.hpp>

namespace lc
{
        //0,0,1,1,1,2,2,3,3,4
        int removeDuplicates(std::vector<int>& nums)
        {
            if( nums.size() == 0 )
                return 0;

            int compare_to = 0;
            for (size_t i = 1; i < nums.size(); ++i)
            {
                if( nums[i] != nums[compare_to] )
                {
                    compare_to ++;
                    nums[compare_to] = nums[i];
                }
            }

            return compare_to + 1;
        }
}

