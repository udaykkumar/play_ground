#include <tuple>
#include <iostream>

std::tuple<int, double> returnTuple()
{
    return std::make_tuple(1,2);
}


int main()
{
    int     a;
    double  b;

    std::tuple<int, double> intTuple =  returnTuple();
        std::tie( a,b )              =  returnTuple();

        std::cout << "intTuple 1st Element " << std::get<0>( intTuple ) << " 2nd Element "  << std::get<1>( intTuple ) << std::endl;
        std::cout << "intTuple 1st Element " << a << " 2nd Element "  << b << std::endl;

    int     x;
    double  y;
        std::tie( x, y ) = intTuple;
        std::cout << "intTuple 1st Element " << x << " 2nd Element "  << y << std::endl;


    return 0;
}
