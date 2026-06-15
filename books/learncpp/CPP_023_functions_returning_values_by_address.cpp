#include <iostream>

int* returnByAddress(int x)
{
	int *arr = new int[x];
	return arr;
}

int main()
{
	std::cout << "calling function returnByAddress with value 5 " << std::endl;
	int *a = returnByAddress(5);
	std::cout << "filling the array " << a
			<< " returned by  function returnByAddress with value 5 "
			<< std::endl;
	for (int i = 0; i < 5; i++)
		a[i] = i;

	std::cout << "printing the array " << a << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	return 0;
}
