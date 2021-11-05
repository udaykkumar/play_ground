#include <iostream>

namespace ds
{
	std::string decimal_to_binary( int d )
	{
		if ( d < 0  ) return "Can't convert -ve numbers for now";
		if ( d == 0 ) return "0";
		
		std::string bin{""};
			for ( ; d ; d >>= 1 ) 
			{
				bin = std::to_string(d%2) + bin;
			}
		return bin;
	}
}

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