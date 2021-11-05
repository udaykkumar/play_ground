#include <iostream>
#include <algorithm>
#include <vector>

namespace ds
{
	bool is_pallindorome( std::string s )
	{
		if ( s.size() == 0 ) return false;

		std::transform( s.begin(), s.end(), s.begin(), ::toupper );
		s.erase( std::remove( s.begin(), s.end(), ' '), s.end() );

		auto fit{ s.begin()  };
		auto rit{ s.rbegin() }; 
		for ( ; fit < rit.base()  ; fit++, rit ++ ) 
		{
			if ( *fit != *rit )
				return false;
		}

		return true;
	}
}

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
		std::cout << w << " is_pallidrome " << 
					( ds::is_pallindorome(w) ? "Yes" : "No" ) << std::endl;
	}
	return 0;
}