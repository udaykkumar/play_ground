#pragma once
#include <iostream>
#include "033_binary_search.hpp"
namespace ds
{
	int exponential_search( int array[], int size, int val )
	{
		/// it impossible to seach for element 
		/// with a zero size array
		if ( size <= 0 ) return -1;

		/// start with index as 1
		int block_index = 1;

		// we try and narrow down the array exponentially
		// to feed the block to binary_search
		while ( block_index < size && array[block_index] < val )
			block_index *= 2;

		return ds::binary_search( array, block_index/2, std::min(block_index, size)-1, val);
	}
}