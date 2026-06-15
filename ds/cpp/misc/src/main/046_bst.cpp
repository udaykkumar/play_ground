#include <iostream>

#include "046_bst.hpp"

int main(int argc, char const *argv[])
{
	{
		ds::bst<int> t;
			for (int i = 0; i < 10; ++i)
			{
				t.insert(i);
				t.print_in_order();
				std::cout << std::endl;
			}
	}
	
	{
		ds::bst<int> t;
			for (int i = 0; i < 10; ++i)
			{
				t.insert(i);
				t.print_pre_order();
				std::cout << std::endl;
			}
	}

	{
		ds::bst<int> t;
			for (int i = 0; i < 10; ++i)
			{
				t.insert(i);
				t.print_post_order();
				std::cout << std::endl;
			}
	}

	{
		ds::bst<int> t;
			for (int i = 0; i < 10; ++i)
				t.insert(i);
			
			for (int i = 0; i < 20; ++i)
			{
				std::cout << " searching for " << i ;
				auto v = t.search(i);
				if ( v ) {
					std::cout << " Found " << v->value() << std::endl;
				} else {
					std::cout << " Not found " << std::endl;
				}
			}
	
	}

	{
		ds::bst<int> t;
			for (int i = 0; i < 10; ++i)
				t.insert(i);
		std::cout << "min " << t.min() << std::endl;
		std::cout << "max " << t.max() << std::endl;
	}

	return 0;
}