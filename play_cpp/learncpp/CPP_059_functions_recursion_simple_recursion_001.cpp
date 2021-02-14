#include<iostream>
#include<vector>

void recursion(int x)
{
    if( x == 0 )
        return;
    recursion(x-1);
    std::cout << x << std::endl;
}


int main()
{
    recursion(5);
	return 0;
}
