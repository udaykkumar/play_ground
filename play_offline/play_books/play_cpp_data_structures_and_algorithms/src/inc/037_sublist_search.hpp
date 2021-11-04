#pragma once

#include "018_LinkedList.hpp"



namespace ds
{
	template < typename T = int >
	int sublist_search( ds::linked_list<T> &first , ds::linked_list<T> &second )
	{
		/// if both are empty thats a success
		if ( first.count() == 0 && second.count() == 0 )
			return true;

		/// if one of them is empty .. then its false
		if ( first.count() == 0 or second.count() == 0 )
			return false;

		/// both are non-empty 
		return false;

	}
}