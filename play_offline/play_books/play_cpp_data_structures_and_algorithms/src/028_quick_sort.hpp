#pragma once


namespace ds
{

	int partition( int array[], int start_i, int end_i, int size )
	{
		/// invalid indices . Quit immediately
		if ( start_i < 0 or end_i >= size )
			return -1;

		int pivot = (start_i + end_i)/2;
		for ( int i = start_i ; i <= end_i ; )
		{
			if ( array[i] < array[pivot] )
				i++;
			else
			{
				std::swap( array[i], array[end_i]);
				end_i --;
			}
		}

		return pivot;
	}


	void quick_sort_r( int array[], int start_i, int end_i, int size )
	{
		/// invalid indices . Quit immediately
		if ( start_i < 0 or end_i >= size )
			return;

		/// if single element . return nothing to do here
		if ( start_i == end_i )
			return;

		/// if there are only two elements , swap if needed and return
		if ( end_i - start_i == 1 )
		{
			if ( array[end_i] < array[start_i] )
				std::swap( array[start_i], array[end_i]);
			return;
		}



		/// lets partition the array into two

		int pivot = partition( array, start_i, end_i, size);
		if ( pivot == -1 )
			return; /// we can not go any further

		quick_sort_r( array, start_i, pivot, size);
		quick_sort_r( array, pivot+1, end_i, size);

		return;
	}


	void quick_sort( int array[], int size)
	{
		quick_sort_r( array, 0, size - 1, size );
	}
}
