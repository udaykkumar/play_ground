#include "binary-search-tree.hpp"
#include <iostream>

namespace ds {


	<typename T>
	struct bst_node
	{
		T 				value;
		struct bst_node *l, *r;
	};

	bst::bst()
	{
		std::cout << "\n initializing \n";
		return;	
	}

	bst::~bst()
	{
		std::cout << "\n removing \n";
		return;	
	}

	void bst::insert(int v)
	{
		std::cout << "\ninserting " << v << "\n";
		return;
	}

	void bst::remove(int v)
	{
		std::cout << "\nremoving " << v <<  "\n";
		return;
	}

	void bst::find(int v)
	{
		std::cout << "\nfinding " << v << "\n";
		return;
	}

} // ds
	