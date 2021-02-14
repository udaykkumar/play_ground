/*
 * https://practice.geeksforgeeks.org/problems/c-functions-set-1introduction/1
 */

#include <iostream>

int calcSum( int a, int b, int c )
{
    return a + b + c ;
}
int main()
{
    int T;
    for( std::cin >> T; T > 0; T -- )
    {
        int a, b, c ;
            std::cin >> a >> b >> c ;
            std::cout << calcSum( a, b, c ) << std::endl;
    }

    return 0;
}
