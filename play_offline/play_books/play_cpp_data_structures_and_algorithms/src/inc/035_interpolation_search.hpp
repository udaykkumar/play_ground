#pragma once

namespace ds
{
	int interpolation_search( int array[], int start_i, int end_i, int val )
	{
		while ( start_i <= end_i )
		{
			///
			/// lowIndex + (
            ///    (val - arr[lowIndex]) * (highIndex - lowIndex) /
            ///    (arr[highIndex] - arr[lowIndex]));
			int mid =  start_i + 
							((val - array[start_i]) * 
								((end_i - start_i) / (array[end_i] - array[start_i]))) ;

			if ( val == array[mid] )
				return val;

			if ( val < array[mid] )
				end_i = mid-1;
			else
				start_i = mid+1;
		}


		return -1;
	}

	int interpolation_search( int array[], int size , int val )
	{
		return interpolation_search( array, 0, size -1 , val);
	}
}
