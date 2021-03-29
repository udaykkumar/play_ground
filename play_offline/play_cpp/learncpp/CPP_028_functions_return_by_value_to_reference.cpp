#include <iostream>

int returnByValue(int x)
{
	return x + 10;
}

int main()
{
	std::cout
			<< " We call function returnByValue and try to assign this to a reference "
			<< std::endl;
	std::cout << " This is going to now work at all " << std::endl;
	//int &x = returnByValue(5);

	return (0);
}
