#pragma once
#include <vector>
#include <cmath>

namespace ds 
{
	std::vector< std::string > generate_subsequence( std::string s )
	{
		if ( s.size() == 0 ) return {""};
		
		std::vector< std::string > subs ;
		//subs.emplace_back( s.substr(0,1) );
		for ( size_t i = 0; i < s.size() ; ++i )
		{
			auto subseqs = generate_subsequence( s.substr(i+1) );
			for ( auto ss : subseqs ) {
				subs.emplace_back( s.at(i) + ss );
			}
		}
		return subs;
	}


	///
	///	This Algorithm of powerset takes some explanation
	///
	///		to start with depending on the number of elements
	///	We calculate the number of subsets .. happens to be 
	/// 	2 ^ s.size() ; // ^ assume its power of
	///	
	///		that is whole range of binary strings
	/// 		0000 .... s.size()-1
	///			0001
	///			0010
	///			.
	///
	///			1111 .... s.size()-1
	///
	///
	/// 	The algorithm is to find the set bit numbers in this list 
	/// 	map them with index in string and viola we are done
	///
	///		example :
	///			000100 -> maps to picking s[3]
	/// 		101101 -> maps to std::string( s[0] + s[2] + s[3] + s[5] )
	///				so on and so forth
	///		 		
	///
	///		How optimal it is 
	/// 	first n iterations -> 2^size
	///		inside another loop 1 -> n 
	///
	
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
				/// Check if j-th bit in the bitCounter is set
            	/// If so, pick j-th character from str
				if (i & (1 << j))
	                ss += s.at(j);
	        }
			subs.emplace_back(ss);
		}

		return subs;
	}



} // dse
	