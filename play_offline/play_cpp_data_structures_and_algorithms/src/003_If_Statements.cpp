#include <iostream>

int main(int argc, char const *argv[])
{
	int i = int(std::rand());
	if ( i > 10 ) {
		std::cout << "got value greater than 10\n";
	} else {
		std::cout << "got value less than 10\n";
	}
	return 0;
}