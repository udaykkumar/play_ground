#include <iostream>
#include <cmath>

#include "utils.hpp"
#include "036_exponential_search.hpp"

int main(int argc, char const *argv[])
{
	std::cout << " exponential_search " << std::endl;
	
	{
		int size{100} ;
		int *array{utils::generate_sorted_array( size )};
		for ( int i{0}; i < size+1 ; ++i ) {
			 std::cout << "searching for " << i << " result " << 
			 	ds::exponential_search( array, size , i );
			 std::cout << std::endl;
		}
		delete array;
	}

	{
		int size{100000} ;
		int *array{utils::generate_sorted_array( size )};
		std::cout << " exponential_search for " << size << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::exponential_search( array, size , i );
		}
		std::cout << " exponential_search for " << size << " done " <<std::endl;
	
		std::cout << " exponential_search for " << size << " worst case " << std::endl;
		for ( int i{0}; i < size ; ++i ) {
			 ds::exponential_search( array, size , i );
		}
		std::cout << " exponential_search for " << size << " done " <<std::endl;
		
		delete array;
	}

	return 0;
}