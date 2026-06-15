#include <iostream>

int main()
{
	int option = int(std::rand())%4;
	int x = 5;
	int y = 4;

	if ( option == 1 ) {
		std::cout << "do add with " << x << " and " << y << std::endl;
	} else if ( option == 2 ) {
		std::cout << "do sub with " << x << " and " << y << std::endl;
	} else if ( option == 3 ) {
		std::cout << "do mul with " << x << " and " << y << std::endl;
	} else if ( option == 4 ) {
		std::cout << "do divi with " << x << " and " << y << std::endl;
	} else {
		std::cout << " this is not defined no action " << std::endl;
	}

	return 0;
}