#include <iostream>
#include "043_generate_subsequence.hpp"

int main(int argc, char const *argv[])
{
	std::vector < std::string > inputs = 
		{
		 	"abcdef",
		 	"donut"
		};

	for ( auto s : inputs ) 
	{
		for ( auto ss : ds::generate_subsequence(s) ) 
		{
			std::cout << ss << std::endl;
		}
	}

	for ( auto s : inputs ) 
	{
		for ( auto ss : ds::generate_subsequence_by_powerset(s) ) 
		{
			std::cout << ss << std::endl;
		}
	}
	
	return 0;
}