/*
 * https://practice.geeksforgeeks.org/problems/c-if-else-decision-making/0
 */

#include <iostream>

std::string decide ( int x )
{
    if( x > 5 )
    {
        return "Greater than 5";
    }
    else if( x < 5 )
    {
        return "Less than 5";
    }
    else 
    {
        return "Equal to 5";
    }
}
int main()
{
    int T;
    for( std::cin >> T; T > 0 ; T -- )
    {
        int x;
            std::cin >> x;
            std::cout << decide(x) << std::endl;
    }

    return (0);
}
