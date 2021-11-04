#include <iostream>
#include <cmath>

#include "utils.hpp"

namespace ds
{
	int jump_search( int array[], int start_i, int end_i, int val )
	{
		int size = end_i - start_i + 1;
		if ( size <= 0 ) return -1;

		int jump_step{ static_cast< int >(std::sqrt(size)) } ,jump_index{0} ;

		while (jump_index < size && array[jump_index] <= val)
	    {
	        jump_index += jump_step;
	    }

		for (int i{jump_index - jump_step}; i <= std::min(jump_index, size); ++i)
		{
			if ( array[i] == val )
				return val;
		}

		return -1;
	}
}

int main(int argc, char const *argv[])
{
	std::cout << " jump_search " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::jump_search( array, 0, size-1, i );
			 std::cout << std::endl;
		}
		delete array;
	}

	{
		int size{100000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " jump_search for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::jump_search( array, 0, size-1, i );
		}
		std::cout << " jump_search for " << size << " done " <<std::endl;
	
		std::cout << " jump_search for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::jump_search( array, 0, size-1, i );
		}
		std::cout << " jump_search for " << size << " done " <<std::endl;
		
		delete array;
	}

	return 0;
}