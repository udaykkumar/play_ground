#include <iostream>

const char * const   cString = "This is a C-Style String";
const std::string  cppString( "This is a C++11 String" );

int main()
{
	std::cout << cString << std::endl << cppString << std::endl;
	return 0;
}