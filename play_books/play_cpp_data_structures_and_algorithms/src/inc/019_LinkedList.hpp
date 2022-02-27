#pragma once
#include <iostream>

namespace ds {

	template <typename T>
	class Node;
			
	template <typename T>
	class linked_list
	{

		private:
		    int count_;

		public:
		    /// The first node in the list
		    /// or null if empty
		    Node<T> * head_;

		    /// The last node in the list
		    /// or null if empty
		    Node<T> * tail_;

		    /// Constructor
		    linked_list();

		    /// get operation
		    Node<T> * get(int index);

		    /// insert operation
		    void insert_head(T val);
		    void insert_tail(T val);
		    void insert(int index, T val);

		    /// search operation
		    int search(T val);

		    /// remove operation
		    void remove_head();
		    void remove_tail();
		    void remove(int index);

		    /// Additional operation
		    int count();
		    void print();
	};

}


#include "impl/019_LinkedList_impl.hpp"