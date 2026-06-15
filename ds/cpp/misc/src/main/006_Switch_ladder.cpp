#include <iostream>

int main()
{
	int option = int(std::rand())%4;
	int x = 5;
	int y = 4;

	switch(option) {
		case 1:
			std::cout << "do add with " << x << " and " << y << std::endl;
			break;

		case 2:
			std::cout << "do sub with " << x << " and " << y << std::endl;
			break;

		case 3:
			std::cout << "do mul with " << x << " and " << y << std::endl;
			break;

		case 4:
			std::cout << "do divi with " << x << " and " << y << std::endl;
			break;

		default:
			std::cout << " this is not defined no action " << std::endl;
			break;
	}

	return 0;
}