#include <iostream>
#include "utils.hpp"

namespace ds
{
	void quick_sort( int array[], int size)
	{

	}
}

int main(int argc, char const *argv[])
{
	std::cout << "quick_sort " << std::endl;
	std::function< void(int [], int ) > f = ds::quick_sort;
	
	utils::just_a_simple_sort(f);
	utils::just_a_simple_sort_multiple(f);
	utils::huge_sort_ascending(f,1000);
	utils::huge_sort_descending(f,1000);
	return 0;
	return 0;
}