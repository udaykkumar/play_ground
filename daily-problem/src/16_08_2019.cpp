#include <16_08_2019.hpp>
#include <queue>
namespace daily_interview
{
    struct comparator
    {
        bool operator() ( const std::list<int> &l1, const std::list<int> &l2 )
        {
            return l1.front() > l2.front();
        }
    };
    std::list<int> merge( std::vector< std::list<int> >  &lists )
    {
        std::priority_queue< std::list<int>, std::vector< std::list<int> >, comparator >   pq;
        std::list<int> retList;

        for( auto list : lists)
            pq.push( list );

        while( !pq.empty() )
        {
            //* Get the List whose Item is at the top
            auto l = pq.top();
            retList.push_back(l.front());

            // Remove that list from Queue
            pq.pop();

            // Remove the front Item
            l.remove(l.front());

            // if there are still items insert this list back to pq
            if( !l.empty() )
                pq.push(l);
        }

        return retList;

    }
}

