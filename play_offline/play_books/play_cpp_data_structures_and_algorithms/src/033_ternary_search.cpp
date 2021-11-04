#include <iostream>
#include "utils.hpp"

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
}

int main(int argc, char const *argv[])
{
	std::cout << " ternary_search " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::ternary_search( array, 0, size-1, i );
			 std::cout << std::endl;
		}
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " ternary_search for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::ternary_search( array, 0, size-1, i );
		}
		std::cout << " ternary_search for " << size << " done " <<std::endl;
	
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " ternary_search for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::ternary_search( array, 0, size-1, i );
		}
		std::cout << " ternary_search for " << size << " done " <<std::endl;
	
	}

		return 0;
}