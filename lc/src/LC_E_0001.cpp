#include <LC_E_0001.hpp>
#include <algorithm>
#include <unordered_map>

namespace lc
{
    std::vector<int> twoSum_method_1( std::vector<int> &nums, int target)
    {
        std::vector<int> res{-1, -1};

        int  index_1 = 0;
        int  index_2 = 0;
        for(  ; index_1 < nums.size() - 1; ++ index_1 )
        {
            int look_for = (target - nums[index_1]);
            for( index_2 = index_1 + 1; index_2 < nums.size() ; ++ index_2 )
            {
                if( nums[index_2] == look_for)
                {
                    res[0] =  index_1 ;
                    res[1] =  index_2 ;
                    return res;
                }
            }
        }

        return res;
    }


    std::vector<int> twoSum_method_2( std::vector<int> &nums, int target)
    {
        std::vector<int> res{-1, -1};

        for( int  index_1 = 0 ; index_1 < nums.size() ; ++index_1 )
        {
            int look_for = (target - nums[index_1]);
            auto it      = std::find( nums.begin() + index_1 + 1, nums.end(), look_for);
            if( it != nums.end() )
            {
                res[0] =  index_1 ;
                res[1] =  std::distance( nums.begin(), it) ;
                return res;
            }
        }

        return res;
    }

    std::vector<int> twoSum_method_3( std::vector<int> &nums, int target)
    {
        std::vector<int> res{-1, -1};

        for( int  index_1 = 0 ; index_1 < nums.size() - 1; ++index_1 )
        {
            int look_for = (target - nums[index_1]);
            auto it      = std::find( nums.begin() + index_1 + 1, nums.end(), look_for);
            if( it != nums.end() )
            {
                res[0] =  index_1 ;
                res[1] =  std::distance( nums.begin(), it) ;
                return res;
            }
        }

        return res;
    }

    std::vector<int> twoSum_method_4( std::vector<int> &nums, int target)
    {
        std::vector<int> res{-1, -1};
        std::unordered_map<int, size_t> nums_map;

        for( size_t i = 0 ; i < nums.size(); ++ i )
        {
            nums_map.insert( std::make_pair(nums[i], i) );
        }

        for( int  i = 0 ; i < nums.size(); ++ i )
        {
            int look_for = (target - nums[i]);
            auto it = std::find_if( nums_map.begin(),
                                    nums_map.end(),
                                    [ &i, &look_for] ( const std::pair<int, size_t> &t ) -> bool
            {
                return t.first == look_for && t.second != i;
            }
                                  );

            if( nums_map.end() != it )
            {
                res[0] =  i ;
                res[1] =  it->second;
                return res;
            }
        }

        return res;
    }

}

