#include <iostream>
#include "utils.hpp"
namespace ds
{
	void bubble_sort( int array[], int size )
	{
		for ( int j = 0 ; j < size ; ++j )
		{
			for ( int i = 0 ; i < size-j-1 ; ++i )
			{
				/// is i+1 is greater we have ascending order 
				/// preserved no need to swap move on
				if ( array[i] < array[i+1] )
					continue;

				std::swap( array[i], array[i+1] );
			}
		}
	}

	void better_bubble_sort( int array[], int size )
	{
		bool swapped = true;
		for ( int j = 0 ; ( j < size ) and swapped ; ++j )
		{
			swapped = false;
			for ( int i = 0 ; i < size-j-1 ; ++i )
			{
				/// is i+1 is greater we have ascending order 
				/// preserved no need to swap move on
				if ( array[i] < array[i+1] )
					continue;
				swapped = true;
				std::swap( array[i], array[i+1] );
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	{
		std::cout << "bubble sort " << std::endl;
		std::function< void(int [], int ) > f = ds::bubble_sort;
			
		utils::just_a_simple_sort(f);
		utils::just_a_simple_sort_multiple(f);
		utils::huge_sort_ascending(f,1000);
		utils::huge_sort_descending(f,1000);
	}
	
	{
		std::cout << "better_bubble_sort sort " << std::endl;
		std::function< void(int [], int ) > f = ds::better_bubble_sort;
			
		utils::just_a_simple_sort(f);
		utils::just_a_simple_sort_multiple(f);
		utils::huge_sort_ascending(f,1000);
		utils::huge_sort_descending(f,1000);
	}


	return 0;
}