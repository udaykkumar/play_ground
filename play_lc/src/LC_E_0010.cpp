#include <LC_E_0010.hpp>

namespace lc
{
    int strStr(std::string haystack, std::string needle) 
    {
        if( needle.length() == 0 )
            return 0;

        if( needle.length() > haystack.length() )
            return -1;


        for( size_t pos = 0 ; pos < (haystack.length() - needle.length() + 1)  ; pos ++)
            if( needle[0] == haystack[pos] && 
                haystack.compare( pos, needle.length(), needle) == 0 )
                return (int)pos;

        return -1;
    }
}

