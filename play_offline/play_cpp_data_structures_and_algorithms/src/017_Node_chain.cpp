#include <iostream>

namespace ds {
	class Node
	{
		public:
			int  value_;
			Node *next_;
	};

	void print_node( Node *n )
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
	
	Node *n1 = new Node;
	n1->value_ = 1;

	Node *n2 = new Node;
	n2->value_ = 2;

	Node *n3 = new Node;
	n3->value_ = 3;

	Node *n4 = new Node;
	n4->value_ = 4;

	Node *n5 = new Node;
	n5->value_ = 5;

	
	n1->next_ = n2;
	n2->next_ = n3;
	n3->next_ = n4;
	n4->next_ = n5;

	print_node(n1);

	return 0;
}