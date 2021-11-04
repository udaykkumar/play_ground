#pragma once
#include <iostream>
#include <functional>

namespace utils
{

	static void Once()
	{
		static bool done = false;
		if ( not done )
		{
			std::srand(static_cast<unsigned int>(time(0)));
			done = true;
		}
	}

	int get_random_int(int min, int max)
	{
		/// set initial seed value to system clock
		Once();

	    /// static used for efficiency,
	    /// so we only calculate this value once
	    static const double fraction =
	        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	    /// evenly distribute the random number
	    /// across our range
	    return min + static_cast<int>(
	        (max - min + 1) * (std::rand() * fraction));
	}

	void just_a_simple_sort( std::function<void(int[], int)> &f )
	{	
		std::cout << "just_a_simple_sort" << std::endl;
		int array[] = {10, 4, 6, 2, 19, 21, 45, 7};
		size_t size = sizeof(array)/sizeof(*array) ;
		
		f(array, size);
		for (size_t i = 0; i < size; ++i)
			std::cout << array[i] << "  ";
		std::cout << std::endl;
	}

	void just_a_simple_sort_multiple( std::function<void(int[], int)> &f )
	{
		std::cout << "just_a_simple_sort multiple times" << std::endl;
		size_t size = 10;
		for ( int k = 0 ; k < 10 ; ++k )
		{
			int array[size];
			for (size_t i = 0; i < size; ++i)
				array[i] = utils::get_random_int(1, 100);
			
			f(array, size);

			for (size_t i = 0; i < size; ++i)
				std::cout << array[i] << "  ";
			std::cout << std::endl;
		}
	}

	void huge_sort_ascending( std::function<void(int[], int)> &f, size_t size = 100000 )
	{
		std::cout << "huge sort ascending" ;
		{
			int *array = new int[size];
			for (size_t i = 0; i < size; ++i)
			{
				array[i] = i;
			}
			std::cout << " perf sorted from 1 -> " << " " << size << std::endl;
			f(array, size);
			std::cout << "done " << std::endl;
			delete []array;
		}
	}

	void huge_sort_descending( std::function<void(int[], int)> &f, size_t size = 100000 )
	{
		std::cout << "huge sort descending" ;
		{
			int *array = new int[size];
			for (size_t i = size-1; i > 0; --i )
			{
				array[i] = i;
			}
			std::cout << " perf sorted from " << size << " -> 1 " << std::endl;
			f(array, size);
			std::cout << "done " << std::endl;
			delete []array;
		}
	}

	int *generate_random_array( int size, int min, int max )
	{
		int *array = new int[size];
		for (int i = 0; i < size; ++i)
			array[i] = get_random_int(min, max);
		return array;
	}	

	int *generate_sorted_array( int size  )
	{
		int *array = new int[size];
		for (int i = 0; i < size; ++i)
			array[i] = i;
		return array;
	}
}