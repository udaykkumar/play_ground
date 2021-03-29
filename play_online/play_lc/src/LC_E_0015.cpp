#include <LC_E_0015.hpp>
#include <algorithm>
namespace lc
{
    std::vector<int> plusOne( std::vector<int>& digits)
    {
        std::reverse( digits.begin(), digits.end() );

        int carry = 1;
        for( auto &d : digits )
        {
            int res = ( d + carry );
            d       = res%10;
            carry   = res/10;
        }

        if( carry > 0 )
            digits.push_back(carry);

        std::reverse( digits.begin(), digits.end() );

        return digits;
    }
}

