#pragma once
#include <cmath>

namespace ds
{
	int jump_search( int array[], int start_i, int end_i, int val )
	{
		int size = end_i - start_i + 1;
		if ( size <= 0 ) return -1;

		int jump_step{ static_cast< int >(std::sqrt(size)) } ,jump_index{0} ;

		while (jump_index < size && array[jump_index] <= val)
	    {
	        jump_index += jump_step;
	    }

		for (int i{jump_index - jump_step}; i <= std::min(jump_index, size); ++i)
		{
			if ( array[i] == val )
				return val;
		}

		return -1;
	}

	int jump_search( int array[], int size, int val )
	{
		return jump_search( array, 0, size - 1, val) ;
	} 
}
