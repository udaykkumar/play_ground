#include "better-double-linked-list.hpp"

/*Destructor*/
ds::betterdll::~betterdll( )
{
    // TODO Fix this ..
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
int ds::betterdll::addHead(const int d)
{
    if( isEmpty() )
    {
        head_ = new node{d};
        tail_ = head_;
    }
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

int ds::betterdll::addTail(const int d)
{
    if( isEmpty() )
    {
        head_ = new node{d};
        tail_ = head_;
    }
    else
    {
        node *n         = new node{d};
        n->prev_        = tail_;
        tail_->next_    = n;
        tail_           = n;
    } 

    sz_ ++;
    return 0;
}


int ds::betterdll::removeHead()
{
    if( !isEmpty() )
    {
        node *n         = head_;
        head_           = head_->next_;
        if( n->next_ )
        {
            n->next_->prev_ = NULL;
            n->next_        = NULL;
        }

        delete n;
        sz_--;

        return 0;
    } 

    return -1;
}

int ds::betterdll::removeTail()
{
    if( !isEmpty() )
    {
        node *n = tail_;
        tail_   = tail_->prev_;
        if( tail_ )
        {
            tail_->next_ = NULL;
            n->prev_     = NULL;
        }       
        

        delete n;
        sz_ --;

        if( sz_ == 0 )
        {
            head_ = NULL;
            tail_ = NULL;
        }
        
        return 0;
    } 
    return -1;
}



/* Utilities */

void  ds::betterdll::print( void ) const
{
    for( node *c = head_; c ; c = c->next_ )
        std::cout << c->d_ << " " ;
    std::cout << "\n";
}

const size_t  ds::betterdll::size( ) const
{
    return sz_;
}

bool  ds::betterdll::isEmpty( void ) const
{
    return ( sz_ == 0 ) ? true : false;
}



