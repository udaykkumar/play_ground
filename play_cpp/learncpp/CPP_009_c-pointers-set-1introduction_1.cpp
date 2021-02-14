/*
 * https://practice.geeksforgeeks.org/problems/c-pointers-set-1introduction/1
 */

#include <iostream>
void updateVar(int *a)
{
    *a += 10;
    return;
}

int main()
{
    int T;
    for( std::cin >> T; T > 0 ; T -- )
    {
        int x;
            std::cin >> x;
            updateVar(&x);
            std::cout << x << std::endl;
    }

    return (0);
}
