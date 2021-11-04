#include <iostream>

#include "037_sublist_search.hpp"

int main(int argc, char const *argv[])
{
	std::cout << " sublist_search " << std::endl;
	{
		ds::linked_list<int> first;
			{
				for (int i = 0; i < 10; ++i)
					first.insert_head(i);
			}

		ds::linked_list<int> second;
			{
				for (int i = 0; i < 100; ++i)
					second.insert_head(i);
			}

		ds::sublist_search( first, second );
	}
	return 0;
}