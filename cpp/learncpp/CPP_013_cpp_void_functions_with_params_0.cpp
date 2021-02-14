#include <iostream>


void display( int x, int y )
{
    std::cout << "Lets Display and return Nothing " << std::endl;
    std::cout << "The Value of X is " << x << " and Y is " << y << std::endl;
}

int main()
{
    std::cout << "Calling function display() with params 2, 3" << std::endl;
    display(2,3);
    return (0);
}
