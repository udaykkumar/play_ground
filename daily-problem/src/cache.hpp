#ifndef __CACHE_HPP_INCLUDED__
#define __CACHE_HPP_INCLUDED__

namespace bira
{
    struct cache
    {
        cache();
        ~cache();

        int get(void *p);
        void put(void *p);

    };
}

#endif