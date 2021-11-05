#pragma once

#include <memory>

namespace ds
{
	template < typename T >
	class DoubleNode;

	template < typename T > 
	class doubly_linked_list
	{
		
		private:
			// The first DoubleNode in the list
	        // or null if empty
	        std::shared_ptr< DoubleNode<T>>  head_;

	        // The last DoubleNode in the list
	        // or null if empty
	        std::shared_ptr< DoubleNode<T>> tail_;
	    
	        int count_;

	        void make_first_node(T val);
	        void remove_first_node();

	    public:
	        

	        // Constructor
	        doubly_linked_list();

	        // get() operation
	        std::shared_ptr< DoubleNode<T>> get(int index);

	        // Insert() operation
	        void insert_head(T val);
	        void insert_tail(T val);
	        void insert(int index, T val);

	        // search() operation
	        int search(T val);

	        // remove() operation
	        void remove_head();
	        void remove_tail();
	        void remove(int index);

	        // Additional operation
	        int count() const;
	        void print_list();
	        void print_list_backwards();
	};
}

#include "impl/021_DoubleLinkedList_Improved_impl.hpp"