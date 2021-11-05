#include <iostream>
#include "utils.hpp"
#include "031_linear_search.hpp"


int main(int argc, char const *argv[])
{
	std::cout << " linear_seach " << std::endl;
	{
		int size{100}, min{10}, max{50} ;
		int *array{utils::generate_random_array( size, min, max)};
		for ( int i{min}; i < max ; ++i ) {
			 ds::linear_search( array, size, i );
		}
	
	}

	{
		int size{10000000}, min{10}, max{50} ;
		int *array{utils::generate_random_array( size, min, max)};
		std::cout << " linear_search for " << size << std::endl;
		for ( int i{min}; i < max ; ++i ) {
			 ds::linear_search( array, size, i );
		}
		std::cout << " linear_search for " << size << " done " <<std::endl;
	
	}

	{
		int size{10000000}, min{10}, max{50} ;
		int *array{utils::generate_random_array( size, min, max)};
		std::cout << " linear_search for " << size << " worst case " << std::endl;
		for ( int i{min}; i < max ; ++i ) {
			 ds::linear_search( array, size, -1 );
		}
		std::cout << " linear_search for " << size << " done " <<std::endl;
	
	}

		return 0;
}