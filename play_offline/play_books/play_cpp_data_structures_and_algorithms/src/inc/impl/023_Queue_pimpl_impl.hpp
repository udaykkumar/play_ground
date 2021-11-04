#include "023_Queue_pimpl.hpp"
#include <iostream>

namespace ds
{
	template < typename T >
	class Node
	{
		private :
			T value_;
			std::shared_ptr< Node > next_;
		
		public :
			Node( T val ) :
				value_ (val)
			{

			}

			~Node() 
			{

			}
			
			std::shared_ptr< Node<T> > &next() { return next_; }
			T 						   value() { return value_;}
	};


	template < typename T >
	class queue_pimpl
	{
		private :
			int count_;
			std::shared_ptr< Node<T> > front_;
			std::shared_ptr< Node<T> > back_;

		public:

			queue_pimpl() :
				count_(0)
			{

			}

			~queue_pimpl()
			{

			}

			bool is_empty()
			{
				return count_ == 0 ;
			}

			T  front()
			{
				if ( is_empty() )
					return -1;

				return front_->value();
			}

			T  back()
			{
				if ( is_empty() )
					return -1;

				return back_->value();
			}

			void enqueue(T val)
			{
				auto n = std::make_shared< Node<T> >(val);

				if ( count_ == 0 )
				{
					front_ = n;
					back_  = n;
				}
				else
				{
					back_->next() = n;
					back_ = back_->next();
				}
				
				count_ += 1;
			}

			void  dequeue()
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
					front_ = front_->next();
				}
				
				count_ -= 1;
			}
	};

	template < typename T >
	queue<T>::queue():
		pimpl_( std::make_shared< queue_pimpl<T> >())
	{

	}

	template < typename T >
	queue<T>::~queue()
	{

	}

}

