#pragma once
#include <iostream>
namespace ds
{
	int binary_to_decimal( std::string s )
	{
		const unsigned int mask{0x01};
		
		int bin = 0;
		for ( auto i{s.begin()}; i != s.end(); ++i )
		{	
			bin <<= 1;
			if ( *i == '0' )
				bin &= ~mask;
			else
				bin |= mask;
		}

		return bin;
	}
}

