#pragma once

#include <iostream>
#include <memory>

namespace ds
{
	template < typename T >
	class Node;

	template < typename T >
	class stack 
	{
		private:
			int count_;
			std::shared_ptr< Node<T> > top_;

		public:
			stack();
			~stack();

			bool is_empty() const;
			T    top();
			void push(T val);
			void pop();
	};
}


#include "impl/022_Stack_impl.hpp"