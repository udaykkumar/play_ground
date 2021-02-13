#include<iostream>
#include<cstdarg>


int sum( int x, ... )
{
    int r = 0;
    va_list list;
    va_start( list, x );
    for( int i = 0 ; i < x; i ++ )
    {
        r += va_arg( list, int );
    }

    return r;
}

int main()
{
    std::cout << " sum(1,2,3,4,5) " << sum(5 /*Sum of the next 5 args */, 1,2,3,4,5) << std::endl;
    std::cout << " sum(1,2,3,4,5,6,7,8) " << sum(8 /* Get sum of next 8 arguments */ ,1,2,3,4,5,6,7,8) << std::endl;
	return 0;
}
