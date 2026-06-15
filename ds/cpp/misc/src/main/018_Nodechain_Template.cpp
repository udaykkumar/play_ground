#include <iostream>

namespace ds
{
	template < typename T >
	class Node
	{
		public:
			Node(T v) :
				value_(v)
			{

			}

				T   value_;
			Node<T> *next_;
	};

	template < typename T >
	void print_node( Node<T> *n )
	{
		while( n != nullptr )
		{
			std::cout << n->value_ << " " ;
			n = n->next_;
		}
		std::cout << std::endl;
	}
}


int main(int argc, char const *argv[])
{
	using namespace ds;
	
	Node<std::string> *n1 = new Node<std::string>("One");
	Node<std::string> *n2 = new Node<std::string>("two");
	n1->next_ = n2;
	
	print_node(n1);

	return 0;
}