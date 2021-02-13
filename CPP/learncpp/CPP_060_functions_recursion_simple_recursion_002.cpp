#include<iostream>
#include<vector>

void recursion(int x)
{
    if( x == 0 )
        return;

    for( int i = 0 ; i < x ; i ++  )
        std::cout << "*" ;
    std::cout << std::endl;

    recursion(x-1);

    for( int i = 0 ; i < x ; i ++  )
        std::cout << "*" ;
    std::cout << std::endl;
}


int main()
{
    recursion(10);
	return 0;
}
