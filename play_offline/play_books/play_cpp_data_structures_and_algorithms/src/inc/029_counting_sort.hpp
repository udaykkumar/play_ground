#pragma once

namespace ds
{

	int min = 1;
	int max = 100001;

	void counting_sort(int array[], int size)
	{
		int count_array_size = (max - min + 1);

		/// initialize a count_array with all zeros
		int *count_array = new int[ count_array_size ];
		for ( int i = 0 ; i < count_array_size ; ++i )
			count_array[i] = 0;

		/// build the array with keys
		for (int i = 0; i < size; ++i)
		 	count_array[ array[i] ]  += 1;
		
		
		/// re-create the array basd on count_array
		int arr_idx = 0;
		for (int i = 0; i < count_array_size; ++i)
		{
			if ( count_array[i] == 0 )
				continue;
			
			for (int k = 0; k < count_array[i]; ++k)
				array[ arr_idx ++ ] = i;
		}

		delete count_array;  
	}
}
