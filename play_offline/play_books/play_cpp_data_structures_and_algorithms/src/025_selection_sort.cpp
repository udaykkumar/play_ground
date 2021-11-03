#include <iostream>
#include "utils.hpp"
namespace ds
{
	void selection_sort( int array[], int size )
	{
		for( int i{0} ; i < size ; ++i )
		{
			int min_index {i};
			for ( int j{i+1} ; j < size ; ++j )
			{
				if ( array[j] < array[min_index] )
					min_index = j;
 			}
 			std::swap( array[min_index], array[i] );
		}
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "selection_sort " << std::endl;
	std::function< void(int [], int ) > f = ds::selection_sort;
		
	utils::just_a_simple_sort(f);
	utils::just_a_simple_sort_multiple(f);
	utils::huge_sort_ascending(f,1000);
	utils::huge_sort_descending(f,1000);

	return 0;
}