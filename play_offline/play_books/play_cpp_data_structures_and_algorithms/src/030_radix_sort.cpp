#include <iostream>
#include "utils.hpp"

namespace ds
{



	void radix_sort( int array[], int size)
	{
		radix_sort_r( array, 0, size - 1, size );
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "radix_sort " << std::endl;
	std::function< void(int [], int ) > f = ds::radix_sort;
	
	utils::just_a_simple_sort(f);
	utils::just_a_simple_sort_multiple(f);
	utils::huge_sort_ascending(f, 10000000);
	utils::huge_sort_descending(f,10000000);
	return 0;
	return 0;
}