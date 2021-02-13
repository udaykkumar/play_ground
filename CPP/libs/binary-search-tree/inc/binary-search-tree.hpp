#ifndef __BINARY_SEARCH_TREE_HPP_INCLUDED__
#define __BINARY_SEARCH_TREE_HPP_INCLUDED__

	
namespace ds {

	struct bst_node ;

	struct bst {

		bst();
		~bst();
		
		void insert( int v );
		void remove( int v );
		void find( int v );

	private:
		struct bst_node *tree_head;

	} ; 

} // ds	

#endif
