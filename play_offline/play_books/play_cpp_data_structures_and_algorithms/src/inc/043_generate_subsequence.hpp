#pragma once
#include <vector>
#include <cmath>

namespace ds 
{
	std::vector< std::string > generate_subsequence( std::string s )
	{
		if ( s.size() == 0 ) return {""};
		
		std::vector< std::string > subs ;
		subs.emplace_back( s.substr(0,1) );
		for ( size_t i = 0; i < s.size() ; ++i )
		{
			auto subseqs = generate_subsequence( s.substr(i+1) );
			for ( auto ss : subseqs ) {
				subs.emplace_back( s.at(i) + ss );
			}
		}
		return subs;
	}


	std::vector< std::string > generate_subsequence_by_powerset( std::string s )
	{
		size_t    size =  s.size();
		const size_t btc  =  static_cast<int>(pow(2, size));
		std::vector< std::string > subs ;
		for ( size_t i = 1 ; i < btc ; ++i )
		{
			std::string ss{""};
			for ( size_t j = 0; j < size ; ++j )
			{
				if (i & (1 << j))
	                ss += s.at(j);
	        }
			subs.emplace_back(ss);
		}

		return subs;
	}



} // dse
	