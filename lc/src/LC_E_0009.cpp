#include <LC_E_0009.hpp>

namespace lc
{
    int removeElement(std::vector<int>& nums, int val)
    {
        int index = 0;
        for( int i = 0 ; i < nums.size();  i ++ )
            if( nums[i] != val )
                nums[index++] = nums[i];

        return index;
    }
}

