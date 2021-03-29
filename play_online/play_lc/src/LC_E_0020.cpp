#include <LC_E_0020.hpp>

namespace lc
{
        void merge(std::vector<int>& nums1, int m,std::vector<int>& nums2, int n)
        {
            std::vector<int> nums;
            for( int i = 0, j = 0 ; ; )
            {
                if( i == m && j == n )
                    break;

                if( i < m && j < n )
                {
                    if( nums1.at(i) < nums2.at(j) )
                        nums.push_back( nums1.at(i++) );
                    else
                        nums.push_back( nums2.at(j++) );
                }
                else if ( i < m )
                    nums.push_back( nums1.at(i++) );
                else
                    nums.push_back( nums2.at(j++) );   
                
            }

            int i = 0;
            for( auto x : nums )
                nums1[ i ++ ] = x;
            
        }
}

