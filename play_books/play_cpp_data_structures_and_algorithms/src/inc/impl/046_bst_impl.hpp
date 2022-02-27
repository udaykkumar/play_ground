#pragma once
#include <iostream>

namespace ds
{
	template < typename T = int>
	class bst_node
	{

		private:
			T value_;
			std::shared_ptr< bst_node<T> > left_;
			std::shared_ptr< bst_node<T> > right_;
		
		public:
			bst_node( T v ):
				value_(v)
			{

			}

			~bst_node()
			{

			}

			T& value() 
			{ 
				return value_ ; 
			}		

			std::shared_ptr< bst_node<T> >& left() { return left_; }
			std::shared_ptr< bst_node<T> >& right() { return right_; }
					
	};

	template < typename T = int>
	class bst_impl
	{
		private:
			std::shared_ptr< bst_node<T> > root_;

		public:
			bst_impl()
			{

			}

			~bst_impl()
			{

			}

			std::shared_ptr< bst_node<T> > insert( std::shared_ptr< bst_node<T> > root, T v )
	        {
	            if ( not root ) 
	            {
	            	root = std::make_shared< bst_node<T> >(v);
	            }
	            else if ( v < root->value() )
	            {
	            	root->left() = insert( root->left(), v );
	            }
	            else {
	            	root->right() = insert( root->right(), v);
	            }
	            
	            return root;
	        }

	        std::shared_ptr< bst_node<T> > search( T v )
	        {
	        	auto r = root();
	        	while ( r )
	        	{
	        		if ( r->value() == v )
	        			return r;
	        		else if ( v < r->value() )
	        			r = r->left();
	        		else 
	        			r = r->right();
	        	}
	            return nullptr;
	        }

	        T    min()
	        {
	        	if ( not root() ) return T();

	        	auto r = root();
	        	while ( r && r->left() )
	        		r = r->left();
	            return r->value();
	        }

	        T 	 max()
	        {
	            if ( not root() ) return T();
	        	
	        	auto r = root();
	        	while ( r && r->right() )
	        		r = r->right();
	            return r->value();
	        }

	        std::shared_ptr< bst_node<T> > successor(T v)
	        {
	            auto r = root();
	        	if ( r and r->val() == v )
	        		return r->right();

	        	while (r)
	        	{
	        		if ( v < r->value() )
	        		{
	        			if ( r->left() and r->left()->value() == v )
	        				return r;
	        			r = r->left();
	        		}
	        		else
	        		{
	        			if ( r->right() and r->right()->value() == v )
	        				return r;
	        			r = r->right();
	        		}
	        	}
	            return nullptr;
	        }

	        std::shared_ptr< bst_node<T> > predecessor(T v)
	        {
	        	auto r = root();
	        	if ( r and r->val() == v )
	        		return r;

	        	while (r)
	        	{
	        		if ( v < r->value() )
	        		{
	        			if ( r->left() and r->left()->value() == v )
	        				return r;
	        			r = r->left();
	        		}
	        		else
	        		{
	        			if ( r->right() and r->right()->value() == v )
	        				return r;
	        			r = r->right();
	        		}
	        	}
	            return nullptr;
	        }


	        void remove(std::shared_ptr< bst_node<T> > root, T v)
	        {
	        	return ;
	        }

	        void preorder(std::shared_ptr< bst_node<T> > r)
	        {
	        	if (r)
	        	{
	        		std::cout << r->value() << " ";
	        		preorder(r->left());
	        		preorder(r->right());
	        	}
	            return ;
	        }

	        void inorder(std::shared_ptr< bst_node<T> > r)
	        {
	        	if (r)
	        	{
	        		inorder(r->left());
	        		std::cout << r->value() << " ";
	        		inorder(r->right());
	        	}
	            return ;
	        }

	        void postorder(std::shared_ptr< bst_node<T> > r)
	        {
	        	if (r)
	        	{
	        		postorder(r->left());
	        		postorder(r->right());
	        		std::cout << r->value() << " ";
	        		
	        	}
	            return ;
	        }

	        std::shared_ptr< bst_node<T> >& root() { return root_; }
	};
} // ds