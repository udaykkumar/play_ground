#include <iostream>

int sum( int x, int y, int z )
{
    return x + y + z;
}

int main()
{
    std::cout << "Calling function sum with arguments ( 3, 4, 5  )" << std::endl;
    std::cout << "sum(3,4,5) retuned " << sum(3,4,5) << std::endl;
    return (0);
}
