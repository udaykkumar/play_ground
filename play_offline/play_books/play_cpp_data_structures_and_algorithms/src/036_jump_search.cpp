#include <iostream>
#include <cmath>

#include "utils.hpp"
#include "035_jump_search.hpp"

int main(int argc, char const *argv[])
{
	std::cout << " jump_search " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::jump_search( array, size , i );
			 std::cout << std::endl;
		}
		delete array;
	}

	{
		int size{100000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " jump_search for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::jump_search( array, size , i );
		}
		std::cout << " jump_search for " << size << " done " <<std::endl;
	
		std::cout << " jump_search for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::jump_search( array, size , i );
		}
		std::cout << " jump_search for " << size << " done " <<std::endl;
		
		delete array;
	}

	return 0;
}