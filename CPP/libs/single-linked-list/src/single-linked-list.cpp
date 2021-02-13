#include "single-linked-list.hpp"
#include <iostream>


/* Destructor */

ds::sll::~sll( )
{
    /* This code is causing faults ... why ?? **/
    /* Becuase new needs to be freed using delete not free and it took 2 days and valgrind to figure that out */
    while( head_ ) 
    {
        node *t = head_;
        head_= head_->next_;
        delete t;
    }
}

/* Member Functions and Utilities */
bool      ds::node::isLastNode() const
{
    return ( next_ == NULL ) ? true : false;
}

bool      ds::sll::isEmpty() const
{
    return ( getHead() == NULL ) ? true : false;
}

ds::node* ds::sll::getLastNode() const 
{
    node *c = getHead();
    while( c->isLastNode() == false ) c = c->next_;
    return c;
}

size_t ds::sll::size( ) const
{
    return sz_;
}

ds::node* ds::sll::getHead( ) const
{
    return head_;
}

void ds::sll::print( ) const 
{
    for( node *n = getHead(); n ; n = n->next_ )
    {
        std::cout << " " << n->d_;
    }
    std::cout <<"\n";
}


/* Get */

int ds::sll::get( const size_t pos )
{
    if( !isEmpty() )
    {
        node  *c = getHead();
        size_t i = 1;
        for( i = 1; c && i < pos ; i ++ )
            c = c->next_;

        if( c  && i == pos )
            return c->d_;
            
    }

    return -1;
}
/* List add and Company  */

int ds::sll::addHead(const int x) 
{

    /* If no head yet*/
    if( isEmpty() ) 
    {
        /* Make a node and make this head */
        head_ = new node{x};
        sz_ ++;
        return 0;
    }

    /* We have a Head, lets assume add is always at the beginning */
    node *n = new node{x};
    n->next_ =  getHead() ;
       head_ = n;

    sz_ ++;
    return 0;
}

int ds::sll::addTail(const int x) 
{

    /* If no head yet*/
    if( isEmpty() ) 
    {
        /* Make a node and make this head */
        head_ = new node{x};
        sz_ ++;
        return 0;
    }

    node   *c{ getLastNode()  } ;
    c->next_ =  new node{x};

    sz_ ++; 
    return 0;
}


int ds::sll::addAfterPosition(const int x, const size_t pos)
{
    if( isEmpty() )
    {
        return addHead(x);
    }

    node *c = getHead();
    for( size_t i = 1 ; ( i < pos ) && c ; i ++ )
    {
        c = c->next_;
    }

    node *n = new node{x};
    n->next_ = c->next_;
    c->next_ = n;
    
    sz_ ++ ;
    return 0;
}

int ds::sll::addBeforePosition(const int x, const size_t pos)
{
    if( isEmpty() )
    {
        return addHead(x);
    }

    node *c = getHead();
    for( size_t idx = 1; ( idx < pos-1 ) && c ; idx ++ )
    {
        c = c->next_;
    }

    node *n = new node{x};  
    n->next_ = c->next_;
    c->next_ = n;

    sz_ ++ ;
    return 0;
}



/* List Remove and Company */


int ds::sll::removeHead( void )
{
    int ret = -1;
    if( isEmpty()  == false ) {
        node *c = getHead();
        head_   = c->next_;
        c->next_= NULL;

        ret = c->d_;
        /* Freeing, Almost forgot this */
        /* Update called deleting **/
        delete c;
        sz_ --;
    }
    return ret;
}

int ds::sll::removeTail( void )
{
    int ret = -1;

    if( isEmpty()  == false ){
        if( head_->next_  == NULL ) 
        {
            return removeHead();
        }
        else
        {
            node *c = getHead();
            while( c->next_ && c->next_->next_ )
                c = c->next_;

            node *t = c->next_;
            ret = t->d_;
            c->next_ = NULL;
            /* Freeing, Almost forgot this */
            /* Update called deleting **/
            delete t;
            sz_ --;
        }
    }
    return ret;
}

int ds::sll::removeAtPosition( const size_t pos )
{
    int ret = -1;

    if( isEmpty( ) || pos > sz_)
        return ret;

    if( pos == 1 )
        return removeHead();

    node      *c = getHead();
    size_t  cpos = 1;

    while( (cpos < pos-1) && c )
    {
        c = c->next_;
        cpos ++;
    }

    if( c  && c->next_ )
    {
        node *t  = c->next_;
        c->next_ = c->next_->next_;
        t->next_ = NULL;
        ret = t->d_;
        delete t;
        sz_--;
    }

    return ret;

}

/* Miscellaneous Company */
int ds::sll::appendList( const ds::sll &list )
{
    if( ! list.isEmpty() )
    {
        for( node *c = list.getHead(); c ; c = c->next_ )
            addTail(c->d_);
    }
    return 0;
}



