#include <iostream>

void add(int a, int b, int &outRes)
{
	outRes = (a + b);
}

void add(int a, int b, double &outRes)
{
	outRes = (a + b);
}

int main()
{
	int x;
	std::cout << "So we call the function to get integer result " << std::endl;
	add(2, 3, x);
	std::cout << "result " << x << std::endl;

	double d;
	std::cout << "So we call the function to get double result " << std::endl;
	add(2, 3, d);
	std::cout << "result " << d << std::endl;
	return (0);
}
