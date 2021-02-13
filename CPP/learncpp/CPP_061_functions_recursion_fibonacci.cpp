#include<iostream>
#include<vector>

int fibonacci(int f)
{
    if( f == 0 )
        return 0;
    if( f == 1 )
        return 1;

    return fibonacci( f-1 ) + fibonacci(f-2);
}


int main()
{
    for( int i = 0 ; i < 10 ; i ++ )
        std::cout << fibonacci(i) <<  "  " ;
	return 0;
}
