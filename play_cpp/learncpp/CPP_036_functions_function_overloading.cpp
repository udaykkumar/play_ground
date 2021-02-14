#include <iostream>

int add( int a, int b )
{
    std::cout <<"Adding Integers" << std::endl;
    return a+b;
}

double add( double a, double b )
{
    std::cout <<"Adding Doubles" << a << " "<< b <<std::endl;
    return a+b;
}

int main()
{
    int x{2}, y{3};
    std::cout << "Integers add(x,y) = " << add(x,y) << std::endl;

    double a{2}, b{3};
    std::cout << "Doubles add(a,b) = " << add(a,b) << std::endl;

    /* 
     * Observer the Call is same for addition and the number of parameters aswell
     * The difference is the argument types
     *
     * That is a very simple overloading
     */
    return (0);
}
