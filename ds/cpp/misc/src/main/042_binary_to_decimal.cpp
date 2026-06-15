#include "041_decimal_to_binary.hpp"
#include "042_binary_to_decimal.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
	int count = 1000;
	for (int i = 0; i < count; ++i)
	{
		std::string bin =  ds::decimal_to_binary(i) ;
		int         dec =  ds::binary_to_decimal(bin) ;
		
		std::cout << " i \t" << i 
				<< " bin \t " << bin << " dec \t" << dec <<  std::endl;
	}
	return 0;
}