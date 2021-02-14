#ifndef __BINRAY_TREE_HPP_INCLUDED__
#define __BINRAY_TREE_HPP_INCLUDED__

#include <iostream>
#include <vector>
#include <functional>

namespace ds
{
    struct tree_node
    {
        int v_;
        struct tree_node *left_, *right_;

        /* Constructor */
        tree_node(int v) : v_(v), left_(NULL), right_(NULL) {}

        /* Members */
        tree_node  *left()
        {
            return left_;
        }
        tree_node *right()
        {
            return right_;
        }
        int          get()
        {
            return v_;
        }

    };


    /* Some Utilities */
    int def_compare( int, int );

    struct binary_tree
    {

        enum display_type { PRE_ORDER, IN_ORDER, POST_ORDER };

        /* Default Ctor */
        binary_tree() : root_(NULL),  sz_(0), compare_( def_compare ) {}

        /* Pass a compare */
        binary_tree( std::function<int(int, int)>  compare ) :
            root_(NULL),  sz_(0), compare_( compare ) {}


        /* Members */
        tree_node       *root()
        {
            return root_;
        }

        /* TreeOps */
        int     del(const int v);
        int     add(const int v);
        int     find(const int v);
        int     findmin();
        int     findmax();


        /* Tree Meta */
        size_t  size() const ;

        /*Miscellaneous Tree*/
        void    display( display_type = PRE_ORDER ) ;


    private:

        tree_node                   *root_;
        size_t                      sz_;
        std::function<int(int, int)> compare_;


        tree_node   *add(tree_node *, const int );
        tree_node   *del(tree_node *, const int );
        int         find(tree_node *, const int )   const;
        void        inorder( tree_node *) ;
        void        preorder( tree_node *) ;
        void        postorder( tree_node *) ;
    };

}

#endif
