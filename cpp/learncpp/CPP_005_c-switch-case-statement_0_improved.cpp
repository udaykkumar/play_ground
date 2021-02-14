/*
 * https://practice.geeksforgeeks.org/problems/c-switch-case-statement/0
 */

#include <iostream>

char numTwoWrods[][10] = { "Nope", "one", "two", "three", "four", "five",
                        "six", "seven", "eight", "nine", "ten" };

static void pronounce( int x )
{
    if( x > 0 && x <= 10 )
    {
        std::cout <<  numTwoWrods[x]  << std::endl;    
    }
    else
    {
        std::cout << "not in range" << std::endl;
    }
}   
int main()
{
    int T;
    for( std::cin >> T; T > 0 ; T -- )
    {
        int x;
            std::cin >> x;
            pronounce(x);
    }

    return (0);
}
