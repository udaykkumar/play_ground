#include <iostream>
#include <functional>
int return5()
{
	return 5;
}

int return10()
{
	return 10;
}

int main()
{
	std::function<int()> fcnPtr;

	fcnPtr = return5;
	std::cout << "calling fcnPtr " << fcnPtr() << std::endl;

	fcnPtr = return10;
	std::cout << "calling fcnPtr " << fcnPtr() << std::endl;
	return (0);
}
