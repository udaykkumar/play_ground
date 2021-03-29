#ifndef __ITERATOR_IM_HPP_INCLUDED__
#define __ITERATOR_IM_HPP_INCLUDED__

#include <iostream>

namespace bira
{
	template< typename type_t >
	struct list
	{
	private:
		struct node ;

	public:
		struct iterator ;

	
		void  			push_back(const type_t x);
		void 			push_front(const type_t x);
		void  			reverse();
		const type_t	back();
		const type_t	front();
		void			pop_back();
		void			pop_front();

		list() :
			start_(nullptr), size_(0) {}

		node*        &root() { return start_ ; 				}
		size_t		  size() { return size_;   				}
		iterator 	  begin(){ return iterator(start_);  	}
		iterator   	  end()  { return iterator(nullptr);  	}

	private:
		struct node* start_;
		size_t		 size_;


		struct node  
		{ 
			node(const type_t x) :
				data_(x), next_(nullptr) {}

			type_t  get() 
			{ 
				return data_; 
			}

			struct node* &next() 
			{ 
				return next_; 
			}

			bool has_next()
			{
				return next_ ? true : false;
			}

			type_t 	data_;
			struct node* next_;
		};

	public:
		struct iterator
		{

			iterator() : 
				current_(nullptr) {}

			iterator(struct node* p) :
				current_(p) {}

			iterator operator++()    
			{ 
				current_ = current_->next(); 
				return *this;
			}

			iterator operator++(int)    
			{ 
				iterator it = *this;
				++ *this;
				return it;
			}

			bool operator!=(const iterator& it) 
			{
				return current_ != it.current_;
			}

			type_t    get()
			{
				return current_->get();
			}


		private:
			struct node* current_;
			
		};

	};
}

#include <IteratorIm_impl.hpp>
#endif