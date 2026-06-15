#pragma once

namespace ds
{
	int binary_search( int array[], int start_i, int end_i, int val )
	{
		while ( start_i <= end_i )
		{
			int mid =  start_i + ((end_i - start_i)/2 ) ;

			if ( val == array[mid] )
				return val;

			if ( val < array[mid] )
				end_i = mid-1;
			else
				start_i = mid+1;
		}


		return -1;
	}

	int binary_search( int array[], int size, int val )
	{
		return binary_search( array, 0, size-1, val);
	}
}
