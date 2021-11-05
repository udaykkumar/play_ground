#include <iostream>
#include <vector>

namespace ds 
{
	inline void transform_to_upper( std::string &s )
	{
		std::transform( s.begin(), s.end(), s.begin(), ::toupper );
	}

	inline void remove_blanks( std::string &s )
	{
		s.erase( std::remove( s.begin(), s.end(), ' ') , s.end() );
	}

	inline void sort_string( std::string &s )
	{
		std::sort( s.begin(), s.end() );
	}

	bool is_anagram( std::string s1, std::string s2 )
	{
		transform_to_upper(s1);
		remove_blanks(s1);
		sort_string(s1);

		transform_to_upper(s2);
		remove_blanks(s2);
		sort_string(s2);

		return s1 == s2;
	}
} // ds


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