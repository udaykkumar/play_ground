#include <iostream>
#include <queue>
#include <memory>
#include "utils.hpp"
#include "031_radix_sort.hpp"

int main(int argc, char const *argv[])
{
	std::cout << "radix_sort " << std::endl;
	std::function< void(int [], int ) > f = ds::radix_sort;
	
	utils::just_a_simple_sort(f);
	utils::just_a_simple_sort_multiple(f);
	utils::huge_sort_ascending(f, 100000);
	utils::huge_sort_descending(f,100000);
	return 0;
}