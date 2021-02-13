#include <iostream>

int print( unsigned int x )
{
    std::cout << x << std::endl;
}

int print( float x )
{
    std::cout << x << std::endl;
}

int main()
{
    std::cout << "Match print(4u)" << std::endl;
    print(4u);

#if 0
    std::cout << "Match Ambiguous " << std::endl;
    print('A'); // wont compile
#endif
    return (0);
}
