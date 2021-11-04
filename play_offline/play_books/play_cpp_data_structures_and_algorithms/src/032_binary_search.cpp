#include <iostream>
#include "utils.hpp"

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
}

int main(int argc, char const *argv[])
{
	std::cout << " binary_search " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::binary_search( array, 0, size-1, i );
			 std::cout << std::endl;
		}
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " binary_search for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::binary_search( array, 0, size-1, i );
		}
		std::cout << " binary_search for " << size << " done " <<std::endl;
	
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " binary_search for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::binary_search( array, 0, size-1, i );
		}
		std::cout << " binary_search for " << size << " done " <<std::endl;
	
	}

		return 0;
}