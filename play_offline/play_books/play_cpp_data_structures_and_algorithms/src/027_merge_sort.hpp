#pragma once


namespace ds
{
	/// [10, 17, 3 , 178, 20 ] [ start_i = 0 ] [end_i = 4] [ size = 5]
	/// 	mid = (0+4)/2 = 2
	///
	///	[10, 17, 3] [ start_i = 0] [ end_i = 2] [ size = 5 ] 
	/// 	mid = (0+2)/2 = 1
	/// 	
	///		[10,17] [ start_i = 0] [end_i = 1] [ size = 5]
	///			return [10,17]

	///		[3] [ start_i = 2] [end_i = 2] [ size = 5]
	///			[3]
	///
	///
	/// 	new_size = 3
	///		a[3] = { }
	/// 	int i = 0;
	///		int j = 0;
	///		int k = 2;
	///	 
	/// [ 178, 20 ] [ start_i = 3] [ end_i = 4] [ size = 5 ] 
	///			return [20,178]



	void merge_sort_r ( int array[] , int start_i, int end_i, int size )
	{
		/// if start index < 0 or end_index >= size we are off boundaries
		/// return immediately
		if ( start_i < 0 or end_i >= size )
			return;

		/// if one element nothing to do 
		/// return immediately
		if ( end_i == start_i )
			return;

		/// if there is a pair 
		/// sort it and we are done
		if ( end_i - start_i == 1 )
		{
			if ( array[end_i] < array[start_i] )
				std::swap( array[end_i], array[start_i] );
			return;
		}


		/// split and sort them recursively
		int mid = ( start_i + end_i ) / 2;

		merge_sort_r( array, start_i, mid, size );
		merge_sort_r( array, mid+1, end_i, size );

		/// create a new array of size e - s + 1
		int new_size = end_i - start_i + 1;
		int *a = new int[new_size];

		/// merge
		{
			int i = 0;
			int j = start_i;
			int k = mid+1;
			while ( j <= mid and k <= end_i )
			{
				if ( array[j] < array[k] )
				{
					a[i++] = array[j++];
				}
				else
				{
					a[i++] = array[k++];
				}
			}

			while ( j <= mid )
				a[i++] = array[j++];

			while ( k <= end_i )
				a[i++] = array[k++];
		}
		

		/// copy
		{
			for ( int i {start_i}, j{0} ; i < new_size ;  )
			{
				array[i++] = a[j++]; 
			}
		}

		delete []a;

	}

	void merge_sort( int array[], int size )
	{
		std::cout << size << std::endl;
		merge_sort_r ( array, 0, size - 1, size );
	}
}
