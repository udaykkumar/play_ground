#pragma once
#include <memory>

namespace ds
{
    template < typename T >
    class bst_node ;

    template < typename T >
    class bst_impl;

    template< typename T >
    class bst
    {
	    private:
	        std::shared_ptr< bst_impl<T> > impl_;

	    public:
	        bst() :
	            impl_ ( std::make_shared< bst_impl<T> >() )
	        {

	        }

	        ~bst()
	        {

	        }

	        void insert( T v )
	        {
	            impl_->root() = impl_->insert(impl_->root(), v);
	        }

	        std::shared_ptr< bst_node<T> >    search( T v )
	        {
	            return impl_->search(v);
	        }

	        T    min()
	        {
	            return impl_->min();
	        }

	        T 	 max()
	        {
	            return impl_->max();
	        }

	        std::shared_ptr< bst_node<T> > successor()
	        {
	            return impl_->successor();
	        }

	        std::shared_ptr< bst_node<T> > predecessor()
	        {
	            return impl_->predecessor();
	        }


	        void remove(T v)
	        {
	        	if ( not impl_->search(v) )
	        		return;
	        	
	            impl_->root() = impl_->remove(impl_->root(), v);
	        }

	        void print_pre_order()
	        {
	            impl_->preorder(  impl_->root() );
	        }

	        void print_in_order()
	        {
	            impl_->inorder( impl_->root() );
	        }

	        void print_post_order()
	        {
	            impl_->postorder(  impl_->root()  );
	        }

    };
} // ds


#include "impl/046_bst_impl.hpp"