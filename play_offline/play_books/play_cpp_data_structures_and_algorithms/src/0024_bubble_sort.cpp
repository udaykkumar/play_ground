#include <iostream>

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
	std::cout << "bubble sort " << std::endl;
	{
		int array[] = {10, 4, 6, 2, 19, 21, 45, 7};
		size_t size = sizeof(array)/sizeof(*array) ;
		
		ds::bubble_sort(array, size);
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << array[i] << "  ";
		}
	
		std::cout << std::endl;
	}

	{
		int array[] = {10, 4, 6, 2, 19, 21, 45, 7};
		size_t size = sizeof(array)/sizeof(*array) ;
		
		ds::better_bubble_sort(array, size);
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << array[i] << "  ";
		}
	
		std::cout << std::endl;
	}

	{
		size_t size = 100000;
		{
			int *array = new int[size];
			for (size_t i = 0; i < size; ++i)
			{
				array[i] = i;
			}
			std::cout << "bubble_sort perf sorted from 1 -> " << " " << size << std::endl;
			ds::bubble_sort(array, size);
			std::cout << std::endl;
		}
	
		{
			int *array = new int[size];
			for (size_t i = 0; i < size; ++i)
			{
				array[i] = i;
			}
			std::cout << "better_bubble_sort perf sorted from 1 -> " << " " << size << std::endl;
			ds::better_bubble_sort(array, size);
			std::cout << std::endl;
		}
	
	}


	{
		size_t size = 100000;
		{
			int *array = new int[size];
			for (size_t i = size-1; i > 0; --i )
			{
				array[i] = i;
			}
			std::cout << "bubble_sort perf sorted from " << size << " -> 1 " << std::endl;
			ds::bubble_sort(array, size);
			std::cout << std::endl;
		}
	
		{
			int *array = new int[size];
			for (size_t i = size-1; i > 0; --i )
			{
				array[i] = i;
			}
			std::cout << "better_bubble_sort perf sorted from " << size << " -> 1 " << std::endl;
			ds::better_bubble_sort(array, size);
			std::cout << std::endl;
		}
	
	}

	return 0;
}