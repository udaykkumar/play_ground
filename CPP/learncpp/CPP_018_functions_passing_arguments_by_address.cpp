#include <iostream>

void passByAddress( int *x )
{
    *x += 10;
}
int main()
{
    int x;
        x = 5;
        std::cout << " x before calling passByAddress() function : " << x << std::endl;
        passByAddress( &x );
        std::cout << " x after returning from passByAddress() function : " << x << std::endl;
}
