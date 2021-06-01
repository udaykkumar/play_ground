#include <iostream>

int add(int a, int b)
{
	return (a + b);
}

double add(double a, double b)
{
	return (a + b);
}

int main()
{
	std::cout << "Match with add(  int, int ) = " << add(1, 3) << std::endl;
	return (0);
}
