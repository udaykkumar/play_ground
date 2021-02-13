#ifndef __SINGLE_LINKED_LIST_HPP__
#define __SINGLE_LINKED_LIST_HPP__
#include <iostream>

namespace ds {

    struct node {
        /* Constructor(s) */
        node(int x) : d_(x), next_(NULL){}

        /* Utilities */
        bool isLastNode() const;

        int d_;
        struct node *next_;
    };

    struct sll {
        
        struct node *head_;
        size_t       sz_;

        /* Constructor(s) */
        sll():head_(NULL), sz_(0){}

        /* Destroy */
        ~sll();

        /* Member Functions */
        size_t  size( void ) const;
        node*   getHead( void ) const;

        /* List Operations */
        int     addHead( const int );
        int     addTail( const int );
        int     addAfterPosition( const int, const size_t );
        int     addBeforePosition( const int, const size_t );

        int     removeHead( void );
        int     removeTail( void );
        int     removeAtPosition( const size_t );


        int     get(const size_t);

        /* Extra Operations */
        int     appendList( const sll &l );

        /* Debug Help */
        void    print( void ) const;

    private:
        node* getLastNode( void ) const;
        bool  isEmpty( void ) const;

    };
};


#endif
