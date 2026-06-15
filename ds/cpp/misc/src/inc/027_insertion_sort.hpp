#pragma once
namespace ds
{
	void insertion_sort( int array[], int size )
	{
		
		for ( int i = 0 ; i < size-1 ;  ++i )
		{
			for ( int j = i+1 ; j > 0  ; --j )
			{
				if ( array[j] < array[j-1] )
					std::swap( array[j], array[j-1] );
			}
		}
	}
}