#pragma once

#include "019_LinkedList.hpp"

namespace ds
{
	template < typename T = int >
	bool sublist_search( ds::linked_list<T> &first , ds::linked_list<T> &second )
	{
		/// if both are empty thats a success
		if ( first.count() == 0 && second.count() == 0 )
			return true;

		/// if one of them is empty .. then its false
		if ( first.count() == 0 or second.count() == 0 )
			return false;

		/// both are non-empty 

		bool match_found = true;
		for ( int second_index = 0  ; second_index < second.count()  ; ++second_index )
		{
			/// match the first value first
			if ( second.get(second_index)->value() != first.get(0)->value() ) 
					 	continue;
			
			/// Try and see if others match
			match_found = true;
			for ( int i{0}, j{second_index} ; 
					i < first.count() and j < second.count() and match_found ; 
					i++, j++ )
			{
				if ( first.get(i)->value() == second.get(j)->value() )
					continue;
				match_found = false ;
			}


			/// if we do find a match we have a match
			if ( match_found ) return true;
		}

		/// this is going to be true if second list matches from end
		return match_found;

	}
}