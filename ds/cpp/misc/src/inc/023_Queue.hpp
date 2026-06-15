#pragma once
#include <memory>

namespace ds
{
	template < typename T>
	class Node;

	template < typename T >
	class queue
	{
		private :
			int count_;
			std::shared_ptr< Node<T> > front_;
			std::shared_ptr< Node<T> > back_;

		public :
			queue();
			~queue();
			bool 	is_empty();
		    T 		front();
		    T 		back();
		    void 	enqueue(T val);
		    void 	dequeue();
	};
}

#include "impl/023_Queue_impl.hpp"
