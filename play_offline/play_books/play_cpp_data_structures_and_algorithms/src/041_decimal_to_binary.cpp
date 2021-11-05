#include <iostream>
#include "041_decimal_to_binary.hpp"
int main(int argc, char const *argv[])
{
	int count = 1000;
	for (int i = 0; i < count; ++i)
	{
		std::cout << " binary form of " << i 
				<< " is \t " << ds::decimal_to_binary(i) << std::endl;
	}
	return 0;
}