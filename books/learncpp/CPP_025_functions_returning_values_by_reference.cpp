#include <iostream>
#include <array>

int& returnByReference(std::array<int, 10> &a, int x)
{
	return a[x];
}

int main()
{
	std::array<int, 10> a;

	std::cout
			<< "Now because the above function returns a refernce to the location at index 5 "
			<< std::endl;
	std::cout << "We can fill that with some values " << std::endl;

	for (int i = 0; i < 10; i++)
		returnByReference(a, i) = i;

	for (int i = 0; i < 10; i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	return 0;
}
