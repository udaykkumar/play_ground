#include <iostream>
#include "utils.hpp"
#include "025_bubble_sort.hpp"

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