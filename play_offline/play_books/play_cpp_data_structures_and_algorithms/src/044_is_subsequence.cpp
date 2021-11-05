#include <iostream>
#include "044_is_subsequence.hpp"
#include "043_generate_subsequence.hpp"

int main(int argc, char const *argv[])
{
	if ( ds::is_subsequence("TEST", "TEST") == true )
		std::cout << "pass " << "TEST" << " TEST \n";

	if ( ds::is_subsequence("LALA", "TEST") == false )
		std::cout << "pass " << "LALA" << " TEST \n";
	else
		std::cout << "failed " << "LALA" << " TEST \n";


	std::vector < std::string > inputs = 
		{
		 	"abcdef",
		 	"donut"
		};

	for ( auto s : inputs ) 
	{
		auto iv = ds::generate_subsequence_by_powerset(s);
		for ( auto i : iv )
		{
			if ( ds::is_subsequence(i, s) == false )
				std::cout << "failed " << i << " " << s << " \n";
			else
				std::cout << "pass " << i << " " << s << " \n";
		}
	}

	for ( auto s : inputs ) 
	{
		auto iv = ds::generate_subsequence_by_powerset(s);
		for ( auto i : iv )
		{
			if ( ds::is_subsequence(i, "TEST") == true )
				std::cout << "failed " << i << " " << "TEST" <<  " \n";
			else
				std::cout << "pass " << i << " " << "TEST" <<  " \n";
		}
	}

	return 0;
}