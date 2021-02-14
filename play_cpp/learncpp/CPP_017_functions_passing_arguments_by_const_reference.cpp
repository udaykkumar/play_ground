#include <iostream>

void passByValue( const int &x, int y )
{
    std::cout << "in function passByValue() Before Incrementing values of x = " << x << " y = " << y << std::endl;
    //x ++;  increment of read-only reference ‘x’ < - x is a constant reference
    y ++;
    std::cout << "in function passByValue() After  Incrementing values of x = " << x << " y = " << y << std::endl;
}
int main()
{
    int x{5};
    int y{5};

        std::cout << "Passing arguments to function passByValue x = " << x << " y = " << y << std::endl;
        passByValue(x,y);
        std::cout << "Values after returning from function x = " << x << " y = " << y << std::endl;

}


