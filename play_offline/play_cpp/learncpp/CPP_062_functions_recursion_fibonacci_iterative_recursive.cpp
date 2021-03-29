#include<iostream>
#include<vector>

int recursive_calls = 0;
int iterative_calls = 0;

int recursive(int f)
{
	recursive_calls++;
	if (f == 0)
		return 0;
	if (f == 1)
		return 1;

	return recursive(f - 1) + recursive(f - 2);
}

int main()
{
	for (int i = 0; i < 10; i++)
		recursive(i);

	int f1 = 0;
	iterative_calls++;
	int f2 = 1;
	iterative_calls++;
	for (int i = 2; i < 10; i++)
	{
		iterative_calls++;
		int f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	std::cout << " Total Recursive calls for generating 10 fibonacci numbers "
			<< recursive_calls << std::endl;
	std::cout << " Total Iterative calls for generating 10 fibonacci numbers "
			<< iterative_calls << std::endl;
	return 0;
}
