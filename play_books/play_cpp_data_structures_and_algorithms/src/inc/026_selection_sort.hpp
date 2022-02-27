#pragma once
namespace ds
{
	void selection_sort( int array[], int size )
	{
		for( int i{0} ; i < size ; ++i )
		{
			int min_index {i};
			for ( int j{i+1} ; j < size ; ++j )
			{
				if ( array[j] < array[min_index] )
					min_index = j;
 			}
 			std::swap( array[min_index], array[i] );
		}
	}
}