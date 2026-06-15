#include <iostream>

int main(int argc, char const *argv[])
{
	const int arr_size = 5;
	/// initialize ptr to an int array
	int *ptr = new int [arr_size] { 1, 3, 5, 7, 9 };

	/// Traverse
	std::cout << "Value \t Address\n";
	while ( *ptr ) {
		std::cout << *ptr << " \t " << ptr << std::endl;
		ptr ++;
	}

	/// move back to original position
	ptr -= arr_size;

	/// Traverse again
	std::cout << "Value \t Address\n";
	while ( *ptr ) {
		std::cout << *ptr << " \t " << ptr << std::endl;
		ptr ++;	
	}

	return 0;
}