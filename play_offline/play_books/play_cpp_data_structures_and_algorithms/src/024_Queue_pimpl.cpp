#include <iostream>
#include "023_Queue_pimpl.hpp"

int main(int argc, char const *argv[])
{
	ds::queue<int> q;

	for (int i = 0; i < 10; ++i)
	{
		/* code */
		q.enqueue(i);
		std::cout << q.back() << "<--";
	}
	std::cout << std::endl;

	while( not q.is_empty() ) 
	{
		std::cout << q.front() << "<--";
		q.dequeue();
	}
	std::cout << std::endl;

	return 0;
}