#include <iostream>
#include <algorithm>

inline int ascending(int a, int b)
{
	return a > b;
}

inline int descending(int a, int b)
{
	return a < b;
}
void sort(int *a, int n, int (*compare)(int, int) = ascending)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (compare(a[min], a[j]))
				min = j;
		}
		std::swap(a[min], a[i]);
	}
}

void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << " " << a[i];

	std::cout << std::endl;
}

int main()
{
	int a[10] =
	{ 5, 2, 3, 6, 7, 1, 9, 0, 8, 4 };

	sort(a, 10);
	print(a, 10);

	sort(a, 10, descending);
	print(a, 10);

	sort(a, 10, ascending);
	print(a, 10);

	return (0);
}
