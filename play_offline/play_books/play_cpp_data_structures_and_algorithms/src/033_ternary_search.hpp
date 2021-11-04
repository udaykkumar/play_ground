#pragma once

namespace ds
{
	int ternary_search( int array[], int start_i, int end_i, int val )
	{
		while ( start_i <= end_i )
		{
			int mid_left_i  = start_i    + ( end_i - start_i ) / 3;
			int mid_right_i = mid_left_i + ( end_i - start_i ) / 3;

			if ( array [ mid_left_i ]  == val ) return val;
			if ( array [ mid_right_i ] == val ) return val;

			if ( val < array [ mid_left_i ] )
			{
				end_i   = mid_left_i  - 1;
			}
			else if ( val > array [ mid_right_i ] )
			{
				start_i = mid_right_i + 1;
			}
			else
			{
				start_i = mid_left_i  + 1;
				end_i   = mid_right_i - 1;
			}
		}


		return -1;
	}

	int ternary_search( int array[], int size, int val )
	{
		ternary_search( array, 0, size-1, val );
	}
}
