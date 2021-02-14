#include "binary-tree.hpp"

int ds::def_compare( int x /*Tree Node*/ , int y /* Value */)
{
	return y - x;
}

size_t ds::binary_tree::size( ) const
{
    return sz_;
}

int ds::binary_tree::del(const int k)
{
	root_ = del( root(), k);
	return 0;
}

ds::tree_node* ds::binary_tree::del( tree_node *r, const int k )
{
	if( r )
	{
		const int res = compare_( r->get(), k);
		if( res == 0 )
		{
			if( r->left() == NULL && r->right() == NULL )
			{
				tree_node *n = r;
				delete n;
				sz_--;
				return NULL;
			}
			else
			{
				if( r->left() == NULL )
				{
					tree_node *n = r;
						       r = r->right();
					n->right_    = NULL;
					delete n;
					sz_--;
				}
				else if ( r->right() == NULL )
				{
					tree_node *n = r;
						       r = r->left();
					n->left_    = NULL;		    
					delete n;
					sz_--;
				}
				else
				{
					int min = 0;
					for( tree_node* c = r->right() ; c ; c = c->left() )
						min = c->v_;

					r->v_ = min;
					r->right_ =  del( r->right(),  min );
				}
			}
		} 
		else if ( res < 0 )
		{
			r->left_ = del( r->left(), k );
		}
		else if ( res > 0 )
		{
			r->right_ = del( r->right(), k );	
		}

	}
	return r;
}


int ds::binary_tree::add(const int v) 
{
	root_ = add(root(), v);
	return 0;
}

ds::tree_node* ds::binary_tree::add(tree_node *r, const int v) 
{
	if( r ) 
	{
		const int 		 res = compare_( r->get(), v );
		if( res < 0 )
			r->left_  = add( r->left(), v);
		else if( res > 0)
			r->right_ = add( r->right(), v);

		return r;
	}
	sz_ ++ ;
	return new tree_node(v);
}

int ds::binary_tree::find(tree_node *r, const int v) const
{
	if( r )
	{
		const int res = compare_( r->get(), v );
		if( res == 0 )
			return r->get();
		if( res <  0 )
			return find( r->left() , v );		
		else
			return find( r->right(), v );
	}
	
	return -1;
}


int ds::binary_tree::find( const int v )
{
	return( size() == 0 ) ? -1 : find( root(), v );
}



void ds::binary_tree::preorder( tree_node *r) 
{
	if(r)
	{
		std::cout << "  " << r->get() ;
		preorder(r->left());
		preorder(r->right());
	}
}


void ds::binary_tree::inorder( tree_node *r) 
{
	if(r)
	{
		inorder(r->left());
		std::cout << "  " << r->get() ;
		inorder(r->right());
	}
}

void ds::binary_tree::postorder( tree_node *r) 
{
	if(r)
	{
		postorder(r->left());   
		postorder(r->right());
		std::cout << "  " << r->get() ;
	}
}
void ds::binary_tree::display( display_type display ) 
{
	std::cout << "display : " ;
	switch( display  ) 
	{
		case IN_ORDER:
			std::cout << " inorder : " ;
			inorder( root() );
			break;
		case PRE_ORDER:
			std::cout << " preorder : " ;
			preorder( root() );
			break;
		case POST_ORDER:
			std::cout << " postorder : " ;
			postorder( root() );
			break;
	}
	std::cout << std::endl;
}


int ds::binary_tree::findmin( )
{
	/* No Min in a zero size tree */
	if( size() == 0 )
		return -1;

	tree_node *n = root();
	while( n->left() )
		n = n->left();

	return n->get();
}


int ds::binary_tree::findmax( )
{
	/* No Min in a zero size tree */
	if( size() == 0 )
		return -1;

	tree_node *n = root();
	while( n->right() )
		n = n->right();

	return n->get();
}
