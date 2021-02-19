/*
 * https://practice.geeksforgeeks.org/problems/c-basic-data-types/0
 */

#include <iostream>


static bool isInt( std::string s )
{
    return  s.find(".") == std::string::npos ;
}

static bool isChar( std::string s )
{
    return (s[0] < '0' || s[0] > '9');
}

static bool isFloat( std::string s )
{
    return (s.size() - s.find(".")) < 7;
}

int main(int ac, char **av)
{
    int T{0};
        std::cin >> T;
        for( ; T > 0 ; T --)
        {
            std::string x;
            int         size;
            std::cin >> x;
            if( isChar(x) )
            {
                size = 1;
            }
            else if( isInt(x) )
            {
                size = 4;
            }
            else if( isFloat(x) )
            {
                size = 4;
            }
            else 
            {
                size = 8;

            }

            std::cout << size << std::endl;

        }

    return (0);
}
