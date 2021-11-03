#include <iostream>

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
	std::cout << "selection sort " << std::endl;
	{
		int array[] = {10, 4, 6, 2, 19, 21, 45, 7};
		size_t size = sizeof(array)/sizeof(*array) ;
		
		ds::selection_sort(array, size);
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
			std::cout << "selection_sort perf sorted from 1 -> " << " " << size << std::endl;
			ds::selection_sort(array, size);
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
			std::cout << "selection_sort perf sorted from " << size << " -> 1 " << std::endl;
			ds::selection_sort(array, size);
			std::cout << std::endl;
		}
	
	}
	return 0;
}