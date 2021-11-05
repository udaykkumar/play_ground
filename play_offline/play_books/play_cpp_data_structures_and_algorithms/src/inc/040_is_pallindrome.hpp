#pragma once

#include <algorithm>

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

