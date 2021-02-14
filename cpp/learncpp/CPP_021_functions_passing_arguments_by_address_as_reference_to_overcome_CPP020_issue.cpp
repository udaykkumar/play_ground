#include <iostream>

void passByAddress( int *&x )
{
    std::cout << " x before changing : " << x << std::endl;
    x = nullptr; 
    std::cout << " x after changing : " << x << std::endl;
}
int main()
{
    int x;
        x = 5;
    int* addressOfx = &x;

        std::cout << " x before calling passByAddress() function : " << x <<  " and addressOfx : " << addressOfx << std::endl;
        passByAddress( addressOfx );
        std::cout << " x after returning from passByAddress() function : " << x << std::endl;
        std::cout << " addressOfx after returning from passByAddress() function : " << &x <<  " and addressOfx is : " << addressOfx << std::endl;

        if( addressOfx == &x  ) 
        {
            std::cerr << " We fail here this can not happen addresses are passed by reference " << std::endl;
            return 0;

        }
                
    return 0;
}
