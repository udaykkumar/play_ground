#include "022_Queue.hpp"
#include <iostream>
namespace ds
{
	template < typename T >
	class Node
	{
		private :
			T value_;
			std::shared_ptr< Node > next_;
			std::shared_ptr< Node > prev_;
		
		public :
			Node( T val ) :
				value_ (val)
			{

			}

			~Node() 
			{

			}
			
			std::shared_ptr< Node<T> > &next() { return next_; }
			std::shared_ptr< Node<T> > &prev() { return prev_; }
			T 						   value() { return value_;}
	};

	template < typename T >
	queue<T>::queue():
		count_(0)
	{

	}

	template < typename T >
	queue<T>::~queue()
	{

	}

	template < typename T >
	bool 	queue<T>::is_empty()
	{
		return count_ == 0 ;
	}

	template < typename T >
	T 		queue<T>::front()
	{
		if ( is_empty() )
			return -1;

		return front_->value();
	}

	template < typename T >
	T 		queue<T>::back()
	{
		if ( is_empty() )
			return -1;

		return back_->value();
	}

	template < typename T >
	void 	queue<T>::enqueue(T val)
	{
		auto n = std::make_shared< Node<T> >(val);

		if ( count_ == 0 )
		{
			front_ = n;
			back_  = n;
		}
		else
		{
			n->next() = back_;
			back_->prev() = n;
			back_ = n;
		}
		
		count_ += 1;
	}

	template < typename T >
	void 	queue<T>::dequeue()
	{
		if ( is_empty() )
			return;

		if ( count_ == 1 )
		{
			back_ = nullptr;
			front_ = nullptr;
		}
		else
		{
			front_ = front_->prev();
			front_->next() = nullptr;
		}
		
		count_ -= 1;
	}

}


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