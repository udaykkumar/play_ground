#include <LC_E_0004.hpp>
#include <unordered_map>
namespace lc
{

    int romanToInt(std::string s)
    {
        std::unordered_map<char, int > SVMap =
        {
            {'I',    1},
            {'V',    5},
            {'X',   10},
            {'L',   50},
            {'C',  100},
            {'D',  500},
            {'M', 1000}
        };

        int res = SVMap.at( s.at(0) );

        int pre_value = res;
        for( size_t i = 1 ; i < s.length() ; ++ i )
        {
            int cur_value =   SVMap.at( s.at(i) );

            res += cur_value;

            if(cur_value > pre_value)
                res -=  (pre_value + pre_value) ;

            pre_value = cur_value;
        }

        return res;
    }

    int romanToInt_Method_2(std::string s)
    {
        int SVMap[255];
        SVMap['I'] =   1;
        SVMap['V'] =   5;
        SVMap['X'] =   10;
        SVMap['L'] =   50;
        SVMap['C'] =   100;
        SVMap['D'] =   500;
        SVMap['M'] =   1000;

        int res = SVMap[ s.at(0) ];

        int pre_value = res;
        for( size_t i = 1 ; i < s.length() ; ++ i )
        {
            int cur_value =   SVMap[s.at(i) ];

            res += cur_value;

            if(cur_value > pre_value)
                res -=  (pre_value + pre_value) ;

            pre_value = cur_value;
        }

        return res;
    }
}

