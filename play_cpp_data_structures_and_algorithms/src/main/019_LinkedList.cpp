#include "019_LinkedList.hpp"


int main(int argc, char const *argv[])
{
	{
		/// declare a list for now
		ds::linked_list<int> lst;

		/// insert element to the head of list
		std::cout << "inserting Elements to head list \n";
		for (int i = 0; i < 10; ++i)
		{
			lst.insert_head(i);
			std::cout << "Total Elements " << lst.count() << std::endl;
			lst.print();
		}
		lst.print();


		/// seach 
		for (int i = 0; i < 15; ++i)
			std::cout << "searching for element " << i << 
						 " " << lst.search(i) << std::endl;


		lst.insert(5,50);
		lst.print();

		lst.insert(6,60);
		lst.print();

		lst.remove(4);
		lst.print();

		lst.remove(2);
		lst.print();
		
		/// delete them
		std::cout << "deleting Elements from head list \n";
		for (int i = 0; i < 20; ++i)
		{
			lst.remove_head();
			std::cout << "Total Elements " << lst.count() << std::endl;
			lst.print();
		}
		lst.print();

	}

	{
		/// declare a list for now
		ds::linked_list<int> lst;

		/// insert at the tail
		std::cout << "inserting Elements to tail list \n";
		for (int i = 0; i < 10; ++i)
		{
			lst.insert_tail(i);
			std::cout << "Total Elements " << lst.count() << std::endl;
			lst.print();
		}
		lst.print();


		for (int i = 0; i < 15; ++i)
			std::cout << "searching for element " << i << 
						 " " << lst.search(i) << std::endl;


		lst.insert(5,50);
		lst.print();

		lst.insert(6,60);
		lst.print();
		

		lst.remove(4);
		lst.print();

		lst.remove(2);
		lst.print();


		std::cout << "deleting Elements from tail list \n";
		for (int i = 0; i < 20; ++i)
		{
			lst.remove_tail();
			std::cout << "Total Elements " << lst.count() << std::endl;
			lst.print();
		}
		lst.print();

	}
	return 0;
}