#pragma once
#include <iostream>
#include <vector>
namespace ds 
{
	std::vector<int> pattern_searching(std::string s, std::string p)
	{
		std::vector<int> indices;
			if ( p.size() <= s.size() )
			{
				for ( size_t i = 0; i < ( s.size() - p.size() ); ++i )
				{
					bool pattern_found = true;
					for ( size_t j = 0; 
							j < p.size() and pattern_found ; ++j )
					{
						if ( s[i + j] != p[j] )
							pattern_found = false;
					}

					if ( pattern_found )
						indices.emplace_back( i );

				}
			}
		return indices;
	}
} // ds
