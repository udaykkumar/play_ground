#include "double-linked-list.hpp"

/*Destructor*/
ds::dll::~dll( )
{
    while( head_ && head_->next_ )
    {
        node *c      = head_;
        head_        = head_->next_;
        head_->prev_ = NULL;
        c->next_     = NULL;
        delete c;
    }

    if( head_ )
        delete head_;
}

/* List Operations */
int ds::dll::addHead(const int d)
{
    if( isEmpty() )
        head_ = new node{d};
    else
    {
        node *n         = new node{d};
        n->next_        = head_;
        n->next_->prev_ = n;
        head_           = n;
    } 

    sz_ ++;
    return 0;
}

int ds::dll::addTail(const int d)
{
    if( isEmpty() )
        head_ = new node{d};
    else
    {
        node *c         = head_;
        while( c->next_ )
            c = c->next_;

        node *n         = new node{d};
        c->next_        = n;
        c->next_->prev_ = c;
    } 

    sz_ ++;
    return 0;
}


int ds::dll::removeHead()
{
    int ret = -1;
    if( !isEmpty() )
    {
        node *n         = head_;
        head_           = head_->next_;
        if( n->next_ )
        {
            n->next_->prev_ = NULL;
            n->next_        = NULL;
        }
        ret = n->d_;
        delete n;
        sz_--;
    } 

    return ret;
}

int ds::dll::removeTail()
{
    int ret = -1;
    if( !isEmpty() )
    {
        node *n = head_;
        while( n->next_ )
        {
            n = n->next_;
        }

        if( n->prev_ )
        {
            n->prev_->next_ = NULL;
            n->prev_        = NULL;
        }

        ret = n->d_; 
        delete n;
        sz_--;
        if( sz_ == 0 )
            head_ = NULL;
    } 
    return ret;
}



/* Utilities */

void  ds::dll::print( void ) const
{
    for( node *c = head_; c ; c = c->next_ )
        std::cout << c->d_ << " " ;
    std::cout << "\n";
}

const size_t  ds::dll::size( ) const
{
    return sz_;
}

bool  ds::dll::isEmpty( void ) const
{
    return ( sz_ == 0 ) ? true : false;
}



