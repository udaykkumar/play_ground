#include <iostream>

// int *returnByAddress( int x )
// {
//     int a = x + 1;
//     return &a; // This address is local
// }

int main()
{
	std::cout << "calling function returnByAddress with value 5 " << std::endl;
	//int *a  = returnByAddress(5);
	std::cout
			<< "at this point address returned by returnByAddress is out of scope "
			<< std::endl;
	std::cout
			<< "reading the value from pointer a is pretty undefined program may work but thats just pure luck ";

	return 0;
}
