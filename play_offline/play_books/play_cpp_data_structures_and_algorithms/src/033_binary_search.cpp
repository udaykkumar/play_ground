#include <iostream>
#include "utils.hpp"
#include "032_binary_search.hpp"

int main(int argc, char const *argv[])
{
	std::cout << " binary_search " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::binary_search( array, size, i );
			 std::cout << std::endl;
		}
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " binary_search for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::binary_search( array, size, i );
		}
		std::cout << " binary_search for " << size << " done " <<std::endl;
	
	}

	{
		int size{10000000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " binary_search for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::binary_search( array, size, i );
		}
		std::cout << " binary_search for " << size << " done " <<std::endl;
	
	}

		return 0;
}