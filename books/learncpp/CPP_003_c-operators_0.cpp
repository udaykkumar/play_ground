/*
 * https://practice.geeksforgeeks.org/problems/c-operators/0
 */

#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return (a > b) ? a - b : b - a;
}

int divide(int a, int b)
{
	return (a > b) ? a / b : b / a;
}

int mul(int a, int b)
{
	return a * b;
}

int main()
{
	int T;
	for (std::cin >> T; T > 0; T--)
	{
		int a
		{ 0 }, b
		{ 0 };
		std::cin >> a >> b;

		std::cout << add(a, b) << std::endl;
		std::cout << sub(a, b) << std::endl;
		std::cout << divide(a, b) << std::endl;
		std::cout << mul(a, b) << std::endl;
	}

	return (0);
}
