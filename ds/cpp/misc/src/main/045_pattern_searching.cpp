#include <iostream>
#include "045_pattern_searching.hpp"

int main(int argc, char const *argv[])
{
	{
		auto ov = ds::pattern_searching( "This is a simple String" , "simple" );
		for ( auto o : ov )
			std::cout << "pattern simple is at index " << o << std::endl;
	}	
	
	{
		auto ov = ds::pattern_searching( "This String is simple" , "simpleString" );
		for ( auto o : ov )
			std::cout << "pattern simpleString is at index " << o << std::endl;

	}

	return 0;
}