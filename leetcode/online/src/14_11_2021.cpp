/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

 */
#include <14_11_2021.hpp>

#include <unordered_map>

namespace daily_interview
{
	std::vector< int > find_pair( std::vector<int> list, int target ) 
	{
		std::vector<int> res{ -1, -1 };
		std::unordered_map<int, int> val_index_map;
		for ( size_t i = 0 ; i < list.size() ; ++i ) {
			val_index_map.insert( std::pair(list[i], i) );
		}

		for ( size_t i = 0 ; i < list.size() ; ++i )
		{
			int t = target - list[i];
			if ( val_index_map.find(t) != val_index_map.end() ) 
			{
				res[0] = t;
				res[1] = val_index_map[t];
				return res;
			}
		}
		return res;
	}
}

