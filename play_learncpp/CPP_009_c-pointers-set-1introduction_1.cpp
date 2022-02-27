/*
 * https://practice.geeksforgeeks.org/problems/c-pointers-set-1introduction/1
 */

#include <iostream>
void updateVar(int *a)
{
	*a += 10;
	return;
}

int main(int ac, char **av)
{
	std::cout << "Skipping " << av[0] << "\n";
	return 0;

	int T;
	for (std::cin >> T; T > 0; T--)
	{
		int x;
		std::cin >> x;
		updateVar(&x);
		std::cout << x << std::endl;
	}

	return (0);
}
