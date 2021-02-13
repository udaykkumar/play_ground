#include <iostream>

int& returnByReference( int x )
{
    static int x1 = x +10; 
    return x1;
}

int main()
{
    int v ;

    std::cout << "We call returnByReference() with value 5" << std::endl;
    std::cout << " and we try to assign it to a value NOT REFERENCE " << std::endl;
        v = returnByReference(5);
    std::cout << " and this is perfectly Okay " << v << std::endl;

    return (0);
}

