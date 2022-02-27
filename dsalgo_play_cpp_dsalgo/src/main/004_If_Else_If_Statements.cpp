#include <iostream>

int main(int argc, char const *argv[])
{
	int i = int(std::rand());
	if ( i > 10 ) {
		std::cout << "got value greater than 10\n";
	} else if ( i < 100 ) {
		std::cout << "got value greater than 10 but less than 100\n";
	} else {
		std::cout << "got value either less than or equal to 10 or greather than equal to 100\n";
	}
	return 0;
}