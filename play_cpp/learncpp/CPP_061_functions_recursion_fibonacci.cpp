#include<iostream>
#include<vector>

size_t fibonacci(size_t f)
{
    if( f <= 1 )
        return f;

    return fibonacci( f-1 ) + fibonacci(f-2);
}


int main()
{
	size_t n = 10;
    for( size_t i = 0 ; i < n ; i ++ ) {
        std::cout << fibonacci(i) <<  "  " ;
    }
	return 0;
}
