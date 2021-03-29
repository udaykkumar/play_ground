#include <iostream>

int defaultArgument(int x = 10, int y = 10, int z = 10)
{
	return x + y + x;
}

int main()
{
	std::cout << "defaultArgument() : " << defaultArgument() << std::endl;
	std::cout << "defaultArgument(5) : " << defaultArgument(5) << std::endl;
	std::cout << "defaultArgument(5,6) : " << defaultArgument(5, 6)
			<< std::endl;
	std::cout << "defaultArgument(5,6,7) : " << defaultArgument(5, 6, 7)
			<< std::endl;

	return (0);
}
