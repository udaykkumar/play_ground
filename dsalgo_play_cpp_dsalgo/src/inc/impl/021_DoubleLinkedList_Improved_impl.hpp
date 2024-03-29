#include <iostream>

#include "021_DoubleLinkedList_Improved.hpp"

namespace ds
{
	template <typename T>
	class DoubleNode
	{
		private:
			T 		value_;
			std::shared_ptr<DoubleNode<T>> next_;
			std::shared_ptr<DoubleNode<T>> prev_;

		public:
			DoubleNode( T v ) :
				value_(v)
			{ }

			~DoubleNode( )
			{ }

			std::shared_ptr<DoubleNode<T>> & next() { return next_; }
			std::shared_ptr<DoubleNode<T>> & prev() { return prev_; }
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
	std::shared_ptr<DoubleNode<T>> doubly_linked_list<T>::get(int index)
	{
		if ( index < 0 )
			return nullptr;
		int c = 0;
		for ( auto p = head_; p ; p = p->next() )
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
				auto p = std::make_shared< DoubleNode<T> >(val);
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
				auto p = std::make_shared<DoubleNode<T>>(val);
				    
				tail_->next() = p;
				tail_->next()->prev() = tail_;
				tail_     = p;
				
				count_ += 1;
		}
	}

	template < typename T >
	void doubly_linked_list<T>::insert(int index, T val)
	{
		if ( auto p = get(index) )
		{
			auto n = std::make_shared<DoubleNode<T>>(val);

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
		for ( auto p = head_; p ; p = p->next() ) {
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
				auto p = head_;
				head_ = head_->next();
				head_->prev() = nullptr;
				
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
				auto p = tail_;
				tail_   = tail_->prev();
				tail_->next() = nullptr;
				count_ -= 1;

		}
	}

	template < typename T >
	void doubly_linked_list<T>::remove(int index)
	{
		if ( auto p = get(index) )
		{
			p->prev()->next() = p->next();
			p->next()->prev() = p->prev();
			p->next() = nullptr;
			p->prev() = nullptr;
			
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

		for ( auto p = head_; p ; p = p->next() )
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


		for ( auto p = tail_; p ; p = p->prev() )
			std::cout << p->value() << " ";
		std::cout << std::endl;
		return;
	}




	template < typename T >
	void doubly_linked_list<T>::make_first_node(T val)
	{
		auto p = std::make_shared<DoubleNode<T>>(val);
		head_ = p;
		tail_ = p;

		count_ += 1;
	}

	template < typename T >
	void doubly_linked_list<T>::remove_first_node()
	{
		tail_ = nullptr;
		head_ = nullptr;

		count_ -= 1;
	}
}
