#include <iostream>

int returnByValue( int x )
{
    return (x + 10);
}

int main()
{
    std::cout << "calling function returnByValue() with value 2" << std::endl;
    std::cout << "return value of function returnByValue() " << returnByValue(2) << std::endl;
    return (0);
}
