#include <iostream>

#include "019_DoubleLinkedList.hpp"

namespace ds
{
	template <typename T>
	class DoubleNode
	{
		private:
			T 		value_;
			DoubleNode<T> *next_;
			DoubleNode<T> *prev_;

		public:
			DoubleNode( T v ) :
				value_(v),
				next_(nullptr)
			{ }

			~DoubleNode( )
			{ }

			DoubleNode<T>* & next() { return next_; }
			DoubleNode<T>* & prev() { return prev_; }
			T 				value() { return value_; }
	};

	// Constructor
	template < typename T >
	doubly_linked_list<T>::doubly_linked_list():
		head_(nullptr),
		tail_(nullptr),
		count_(0)
	{

	}

	// get() operation
	template < typename T >
	DoubleNode<T> * doubly_linked_list<T>::get(int index)
	{
		if ( index < 0 )
			return nullptr;
		int c = 0;
		for ( auto *p = head_; p ; p = p->next() )
		{
			if ( c == index )
				return p;

			c += 1;
		}
		return nullptr;
	}

	// Insert() operation
	template < typename T >
	void doubly_linked_list<T>::insert_head(T val)
	{
		const int nnodes = count();
		switch( nnodes ) {
			case 0:
				/// if there is nothing make first node
				make_first_node(val);
				return;

			default:
				auto *p = new DoubleNode(val);
				p->next() = head_;
				head_     = p;
				head_->next()->prev() = head_; 
				count_ += 1;
		}

	}

	template < typename T >
	void doubly_linked_list<T>::insert_tail(T val)
	{
		const int nnodes = count();
		switch( nnodes ) {
			case 0:
				/// if there is nothing make first node
				make_first_node(val);
				return;

			default:
				auto *p = new DoubleNode(val);
				    
				tail_->next() = p;
				tail_->next()->prev() = tail_;
				tail_     = p;
				
				count_ += 1;
		}
	}

	template < typename T >
	void doubly_linked_list<T>::insert(int index, T val)
	{
		if ( auto *p = get(index) )
		{
			auto *n = new DoubleNode(val);

			/// attach links of n to p and p->next()
			n->prev() = p;
			n->next() = p->next(); 

			/// Sandwitch n between p and p->next
			p->next()->prev() = n;
			p->next() = n;

			count_ += 1;
		}

	}

	// search() operation
	template < typename T >
	int doubly_linked_list<T>::search(T val)
	{
		int index = -1;
		for ( auto *p = head_; p ; p = p->next() ) {
			if ( val == p->value() )
				return index;
			index += 1;
		}
			
		return -1;
	}

	// remove() operation
	template < typename T >
	void doubly_linked_list<T>::remove_head()
	{
		const int nnodes = count();

		switch( nnodes ) {
			case 0:
				/// Nothing much to do incase of empty list
				return;

			case 1:
				remove_first_node();
				return;

			default:
				/// move head by one and remove prev pointer
				auto *p = head_;
				head_ = head_->next();
				head_->prev() = nullptr;
				delete p;

				/// update counter
				count_ -= 1;

		}
	}

	template < typename T >
	void doubly_linked_list<T>::remove_tail()
	{
		const int nnodes = count();
		switch(nnodes)
		{
			case 0:
				return;
			case 1:
				remove_head();
				return;
			default:
				auto *p = tail_;
				tail_   = tail_->prev();
				tail_->next() = nullptr;
				delete p;
				count_ -= 1;

		}
	}

	template < typename T >
	void doubly_linked_list<T>::remove(int index)
	{
		if ( auto *p = get(index) )
		{
			p->prev()->next() = p->next();
			p->next()->prev() = p->prev();
			p->next() = nullptr;
			p->prev() = nullptr;
			delete p;

			count_ -= 1;
		}
	}

	// Additional operation
	template < typename T >
	int doubly_linked_list<T>::count() const
	{
		return count_;
	}

	template < typename T >
	void doubly_linked_list<T>::print_list()
	{
		if ( count() == 0 ) {
			std::cout << " [] \n";
			return;
		}

		for ( auto *p = head_; p ; p = p->next() )
			std::cout << p->value() << " ";
		std::cout << std::endl;
		return;
	}

	template < typename T >
	void doubly_linked_list<T>::print_list_backwards()
	{
		if ( count() == 0 ) {
			std::cout << " [] \n";
			return;
		}


		for ( auto *p = tail_; p ; p = p->prev() )
			std::cout << p->value() << " ";
		std::cout << std::endl;
		return;
	}




	template < typename T >
	void doubly_linked_list<T>::make_first_node(T val)
	{
		auto *p = new DoubleNode(val);
		head_ = p;
		tail_ = p;

		count_ += 1;
	}

	template < typename T >
	void doubly_linked_list<T>::remove_first_node()
	{
		delete head_;
		tail_ = nullptr;
		head_ = nullptr;

		count_ -= 1;
	}
}

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