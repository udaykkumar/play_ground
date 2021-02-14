/*
 * https://practice.geeksforgeeks.org/problems/c-strings/0
 */

#include <iostream>

std::size_t maxLength( std::string s1, std::string s2 )
{
    return (  s1.size() > s2.size() ) ? s1.size() : s2.size();
}

int main()
{
    int T;
    for ( std::cin >> T; T > 0 ; T -- )
    {
        std::string s1{""}, s2{""};
            std::cin >> s1 >> s2;

        std::cout << maxLength(s1,s2) << std::endl;
        std::cout << s1 << s2 << std::endl;
    }
}
