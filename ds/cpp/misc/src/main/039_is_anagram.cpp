#include <iostream>
#include <vector>
#include "039_is_anagram.hpp"


int main(int argc, char const *argv[])
{
	std::vector< std::pair<std::string, std::string> > possible_anagrams = 
		{
			{ "dog", "god" },
			{ "dupe", "pude" },
			{ "leaf" , "noleaf" },
			{ "level" , "lev" },
			{ "D G o", "god "}

		};

	for ( auto v : possible_anagrams ) {
		std::cout << v.first << "\t" << v.second << "\tis_anagram : " << 
					(ds::is_anagram( v.first, v.second ) ? "Yes" : "No" )<< "\n";
	}
	return 0;
}