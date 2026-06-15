#include <iostream>

void passByAddress(const int *x)
{
	// *x += 10; We can not modigy this
	std::cout << "We can't modify this one its const " << std::endl;
}
int main()
{
	int x;
	x = 5;
	std::cout << " x before calling passByAddress() function : " << x
			<< std::endl;
	passByAddress(&x);
	std::cout << " x after returning from passByAddress() function : " << x
			<< std::endl;
}
