#pragma once

namespace ds
{
	int linear_search( int array[], int start_i, int end_i, int val )
	{
		for (int i = start_i; i <= end_i; ++i)
		{
			if ( array[i] == val )
				return val;
		}

		return -1;
	}

	int linear_search( int array[], int size, int val )
	{
		return linear_search(array, 0, size-1, val);
	}
}