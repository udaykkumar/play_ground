#pragma once
#include <memory>

namespace ds
{
	template < typename T >
	class Node;

	template < typename T >
	class queue_pimpl;

	template < typename T >
	class queue 
	{
		private :
			std::shared_ptr<queue_pimpl<T>> pimpl_;

		public :
			queue();
			~queue();
			bool 	is_empty() 		{ return pimpl_->is_empty(); 	} 
		    T 		front()    		{ return pimpl_->front();    	} 	 
		    T 		back()     		{ return pimpl_->back();     	}
		    void 	enqueue(T val) 	{  pimpl_->enqueue(val); 		}
		    void 	dequeue() 		{  pimpl_->dequeue(); 			}
	};
}

#include "impl/023_Queue_pimpl_impl.hpp"