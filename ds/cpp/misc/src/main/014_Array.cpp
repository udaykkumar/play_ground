#include <iostream>

int main(int argc, char const *argv[])
{
	/// initialize array
	int arr[] = { 5, 4, 3, 2, 7 } ;

	/// display array
	std::cout << " array elements are ";
	for( size_t i = 0 ; i < sizeof(arr) / sizeof(*arr) ; ++i )
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	/// manipulate array
	arr[2] = 10;
	arr[4] = 111;

	/// display array again
	std::cout << " array elements are ";
	for( size_t i = 0 ; i < sizeof(arr) / sizeof(*arr) ; ++i )
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}