#pragma once

namespace ds
{
	void bubble_sort( int array[], int size )
	{
		for ( int j = 0 ; j < size ; ++j )
		{
			for ( int i = 0 ; i < size-j-1 ; ++i )
			{
				/// is i+1 is greater we have ascending order 
				/// preserved no need to swap move on
				if ( array[i] < array[i+1] )
					continue;

				std::swap( array[i], array[i+1] );
			}
		}
	}

	void better_bubble_sort( int array[], int size )
	{
		bool swapped = true;
		for ( int j = 0 ; ( j < size ) and swapped ; ++j )
		{
			swapped = false;
			for ( int i = 0 ; i < size-j-1 ; ++i )
			{
				/// is i+1 is greater we have ascending order 
				/// preserved no need to swap move on
				if ( array[i] < array[i+1] )
					continue;
				swapped = true;
				std::swap( array[i], array[i+1] );
			}
		}
	}
}
