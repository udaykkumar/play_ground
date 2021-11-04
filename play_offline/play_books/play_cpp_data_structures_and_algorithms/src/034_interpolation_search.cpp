#include <iostream>
#include "utils.hpp"

namespace ds
{
	int interpolation_searh( int array[], int start_i, int end_i, int val )
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
}

int main(int argc, char const *argv[])
{
	std::cout << " interpolation_searh " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::interpolation_searh( array, 0, size-1, i );
			 std::cout << std::endl;
		}
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " interpolation_searh for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::interpolation_searh( array, 0, size-1, i );
		}
		std::cout << " interpolation_searh for " << size << " done " <<std::endl;
	
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " interpolation_searh for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::interpolation_searh( array, 0, size-1, i );
		}
		std::cout << " interpolation_searh for " << size << " done " <<std::endl;
	
	}

		return 0;
}