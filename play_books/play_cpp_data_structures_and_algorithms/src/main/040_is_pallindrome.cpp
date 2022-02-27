#include <iostream>
#include <algorithm>
#include <vector>
#include "040_is_pallindrome.hpp"

int main(int argc, char const *argv[])
{
	std::vector< std::string > possible_pallindromes = 
		{
			"malayalam",
			"Malayalam",
			"yesey",
			"At",
			"and this is not a pallindrome ",
			" THIS is also not the one",
			" si M alay a lam is "
		};

	for ( auto w : possible_pallindromes ) {
		std::cout << w << " is_pallindorome " << 
					( ds::is_pallindorome(w) ? "Yes" : "No" ) << std::endl;
	}
	return 0;
}