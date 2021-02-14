#include <LC_E_0011.hpp>

namespace lc
{
    //1,3,5,6
    //5
    int searchInsert(std::vector<int>& nums, int target)
    {
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
}

