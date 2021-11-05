#include <iostream>

#include "020_DoubleLinkedList_Improved.hpp"

int main(int argc, char const *argv[])
{
	{
		/// Just pure declarations
		ds::doubly_linked_list<int> int_list;
		ds::doubly_linked_list<std::string> string_list;
	}	

	{
		std::cout << "head operations \n";
		ds::doubly_linked_list<int> dll;
		for (int i = 0; i < 10; ++i)
		{
			dll.insert_head(i);
			std::cout << "Nodes " << dll.count() << "\n";
			dll.print_list();
			dll.print_list_backwards();
		}

		dll.insert(5,50);
		std::cout << "Nodes " << dll.count() << "\n";
		dll.print_list();
		dll.print_list_backwards();
		


		dll.insert(6,60);
		std::cout << "Nodes " << dll.count() << "\n";
		dll.print_list();
		dll.print_list_backwards();
		

		dll.remove(2);
		std::cout << "Nodes " << dll.count() << "\n";
		dll.print_list();
		dll.print_list_backwards();
		


		dll.remove(2);
		std::cout << "Nodes " << dll.count() << "\n";
		dll.print_list();
		dll.print_list_backwards();
		

		for (int i = 0; i < 15; ++i)
		{
			dll.remove_head();
			std::cout << "Nodes " << dll.count() << "\n";
			dll.print_list();
			dll.print_list_backwards();
		}
	}

	{
		std::cout << "tail operations \n";
		ds::doubly_linked_list<int> dll;
		for (int i = 0; i < 10; ++i)
		{
			dll.insert_tail(i);
			std::cout << "Nodes " << dll.count() << "\n";
			dll.print_list();
			dll.print_list_backwards();
		}

		for (int i = 0; i < 15; ++i)
		{
			dll.remove_tail();
			std::cout << "Nodes " << dll.count() << "\n";
			dll.print_list();
			dll.print_list_backwards();
		}
	}

	return 0;
}