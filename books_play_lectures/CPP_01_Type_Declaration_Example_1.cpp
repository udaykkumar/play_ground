#include <iostream>

int main(int argc, char const *argv[])
{
	// well defined: a char has at least 8 bits and can always hold 64 
	unsigned char c1 = 64; 
	
	// implementation-defined: truncation if a char has only 8 bits
	unsigned char c2 = 1256; 

	std::cout << " c1 " << c1 << " c2 " << c2 << "\n";
	return 0;
}