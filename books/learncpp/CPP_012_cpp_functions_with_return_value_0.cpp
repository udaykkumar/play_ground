#include <iostream>

int getSomeThing()
{
	return 2;
}

int main()
{
	int x;
	x = getSomeThing();
	std::cout << "getSomeThing returned : " << x << std::endl;
	return (0);
}
