#include <iostream>
#include <functional>
#include "utils.hpp"

namespace ds
{
	void insertion_sort( int array[], int size )
	{
		
		for ( int i = 0 ; i < size-1 ;  ++i )
		{
			for ( int j = i+1 ; j > 0  ; --j )
			{
				if ( array[j] < array[j-1] )
					std::swap( array[j], array[j-1] );
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	std::cout << "insertion_sort " << std::endl;
	std::function< void(int [], int ) > f = ds::insertion_sort;
	
	utils::just_a_simple_sort(f);
	utils::just_a_simple_sort_multiple(f);
	utils::huge_sort_ascending(f);
	utils::huge_sort_descending(f);
	
	return 0;
}