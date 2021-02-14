#include <shared_ptr_demo.hpp>

namespace daily_interview
{
    namespace details
    {
        std::shared_ptr< std::vector<int> >  v = std::make_shared< std::vector<int> >( ); 
    }

    shared::shared()
    {
        sptr_ = details::v;
    }

    std::weak_ptr< std::vector<int> >      &shared::get()
    {
        return sptr_;
    }

    size_t  shared::size()  const 
    {
        size_t sz = 0;
        if( auto sp = sptr_.lock() )
        {
            sz = (*sp).size();
        }   
        return sz;
    }

    void shared::put(int x)
    {
        if( auto sp = sptr_.lock() )
        {
            (*sp).push_back(x);
        }
    }
}

