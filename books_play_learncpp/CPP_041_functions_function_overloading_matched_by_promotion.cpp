#include <iostream>

int add(int a, int b)
{
	std::cout << "add Int" << std::endl;
	return (a + b);
}

double add(double a, double b)
{
	std::cout << "add doub" << std::endl;
	return (a + b);
}

int main()
{
	std::cout << "Match with add(  int, int ) = " << add(1, 3) << std::endl;
	std::cout << "Match with add(  double, double ) = " << add(1.0, 3.0)
			<< std::endl;

	/* Match by Promotion will hit int, int */
	std::cout << "Match with Promotion add(  int, int ) = " << add('0', 'a')
			<< std::endl;
	return (0);
}
