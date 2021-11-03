#include "018_LinkedList.hpp"

namespace ds
{

	template <typename T>
	class Node
	{
		private:
			T 		value_;
			Node<T> *next_;

		public:
			Node( T v ) :
				value_(v),
				next_(nullptr)
			{

			}

			~Node( )
			{

			}

			Node<T>* & next() {
				return next_;
			}

			T value() {
				return value_;
			}
	};


	/// Constructor
	template < typename T >
		linked_list<T>::linked_list():
			count_(0),
			head_(nullptr),
			tail_(nullptr)
		{

		}

	/// get and family
	template < typename T >
		Node<T> *linked_list<T>::get(int index)
		{
			int counter = 0;
			for ( auto *p = head_; p != nullptr ; p = p->next() ) {
				if ( counter == index ) {
					return p;
				}
				counter ++;
			}
			return nullptr;
		}

	/// insert and friends
	template < typename T >
		void linked_list<T>::insert(int index, T val)
		{
			if (index < 0 || index > count() ) {
				return;
			} 

			if ( index == 0 ) {
				insert_head(val);
				return;
			}
			else if ( index == count()) {
				insert_tail(val);
				return;
			}
			else {
				/// get previour pointer
				if( auto *p = get(index-1) )
				{
					/// Get a node pointer
					auto *n = new Node(val);

					/// let node->next() pointer point to next node
					n->next() = p->next();

					/// let prev point to actual node
					p->next() = n;
					count_ += 1;
				}
			}
			
		}
		
	/// at head	
	template < typename T >
		void linked_list<T>::insert_head(T val)
		{
			/// Create a new Node first
			auto *p = new Node(val);

			/// let it point to head
			p->next() = head_;

			/// move head to point to new node
			head_    = p;

			/// if its a single node reset tail
			if ( head_->next() == nullptr )
				tail_ = head_;

			count_ += 1;
		}

	/// at tail
	template < typename T >
		void linked_list<T>::insert_tail(T val)
		{
			/// if there is no head means there is no list
			/// inserting as head or tail are same
			/// we reuse the same function
			if ( head_ == nullptr ) {
				insert_head(val);
				return;
			}

			/// at this point we should have a valid tail

			/// Create a new Node first
			auto *p = new Node(val);

			/// extend the tail
			tail_->next() = p;

			/// move tail to last
			tail_ = tail_->next();

			count_ += 1;
		}

	/// search
	template < typename T >
	int linked_list<T>::search(T val)
		{
			int counter = 0;
			for ( auto *p = head_; p != nullptr; p = p->next() ) {
				if ( p->value() == val ) {
					return counter;
				}
				counter ++;
			}
			return -1;
		}

	/// remove
	template < typename T >
		void linked_list<T>::remove(int index)
		{
			if ( index < 0 or index > count() )
				return;

			if ( index == 0 )
				remove_head();
			else if ( index == count()-1 )
				remove_tail();
			else {
				if ( auto *p = get(index-1) ) 
				{
					auto *d = p->next();
					p->next() = p->next()->next();
					delete d;

					count_ -= 1;
				}
			}
		}
	
	/// from head
	template < typename T >
		void linked_list<T>::remove_head()
		{
			if ( head_ != nullptr )
			{
				/// lets get the node at head
				auto *p = head_;

				/// move head by one
				head_ = head_->next();
				

				/// if empty reset tail also
				if ( head_ == nullptr ) 
					tail_ = nullptr;

				delete p;

				count_ -= 1;
			}
		}

	/// from tail
	template < typename T >
		void linked_list<T>::remove_tail()
		{
			if ( head_ == nullptr )
				return;

			/// Just one element
			if ( head_ == tail_ )
			{
				remove_head();
				return;
			}

			/// lets get the node at head
			auto *p = head_;

			while ( p->next() != tail_ )
				p = p->next();

			/// p->next() is our tail_
			/// move tail_ to p .. i.e move back
			tail_ = p;

			/// advance p and detach tail
			p = p->next();
			tail_->next() = nullptr;

			delete p;
			count_ -= 1;
		}
	
	/// count
	template < typename T >
		int linked_list<T>::count()
		{
			return count_;
		}

	/// print
	template < typename T >
		void linked_list<T>::print()
		{
			if ( count() == 0 ) {
				std::cout << "empty list \n";
				return;
			}

			for ( auto *p = head_; p != nullptr ; p = p->next() ) {
				std::cout << p->value() << " ";
			}
			std::cout << std::endl;

		}

}

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