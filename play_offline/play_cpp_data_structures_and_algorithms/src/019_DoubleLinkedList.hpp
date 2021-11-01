#pragma once

namespace ds
{
	template < typename T >
	class DoubleNode;

	template < typename T > 
	class DoublyLinkedList
	{
		
		
	    private:
	        int m_count;

	    public:
	        // The first DoubleNode in the list
	        // or null if empty
	        DoubleNode<T> * head_;

	        // The last DoubleNode in the list
	        // or null if empty
	        DoubleNode<T> * tail_;

	        // Constructor
	        DoublyLinkedList();

	        // get() operation
	        DoubleNode<T> * get(int index);

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
	        int count();
	        void print_list();
	        void print_list_backwards();
	};
}