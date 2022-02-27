#include <iostream>
#include "utils.hpp"
#include "035_interpolation_search.hpp"

int main(int argc, char const *argv[])
{
	std::cout << " interpolation_search " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::interpolation_search( array, size, i );
			 std::cout << std::endl;
		}
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " interpolation_search for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::interpolation_search( array, size, i );
		}
		std::cout << " interpolation_search for " << size << " done " <<std::endl;
	
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " interpolation_search for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::interpolation_search( array, size, i );
		}
		std::cout << " interpolation_search for " << size << " done " <<std::endl;
	
	}

		return 0;
}