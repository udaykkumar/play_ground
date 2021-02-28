/*
Hi, here's your problem today. This problem was recently asked by Facebook:

Given a sequence of numbers, find the longest sequence that contains only 2
unique numbers.

Example:

Input: [1, 3, 5, 3, 1, 3, 1, 5]
Output: 4

The longest sequence that contains just 2 unique numbers is [3, 1, 3, 1]

Here's the solution signature:


def findSequence(seq):
  # Fill this in.

print findSequence([1, 3, 5, 3, 1, 3, 1, 5])
# 4


*/
#include <28_07_2019.hpp>

namespace daily_interview
{
    size_t find_sequence( std::vector<int> &seq )
    {
        struct tracker
        {
            std::vector<int> s;
            size_t			 len;
            bool 			 e1_init_done;

            tracker() :
                s(std::vector<int>
            {
                0, 0
            }),
            len(0),
            e1_init_done(false) {}


            bool exists(int x)
            {
                bool yes =  s[0] == x || s[1] == x ;
                if( x == s[1] )
                {
                    return yes;
                }

                s[0] = s[1];
                s[1] = x;
                return yes;
            }

            void update(int x)
            {
                if( e1_init_done == false )
                {
                    e1_init_done = true;
                    len = 0;
                    return;
                }

                len = ( s[0] == s[1] ) ? 0 : 2 ;

            }

            void increment()
            {
                ++len;
            }
            size_t  length()
            {
                return len;
            }

        };

        tracker t;
        size_t  max_seq = 0;
        for( auto s : seq )
        {
            if( t.exists(s) )
            {
                t.increment();
            }
            else
            {
                if( max_seq < t.length() )
                {
                    max_seq = t.length();
                }
                t.update(s);
            }
        }

        if( max_seq < t.length() )
        {
            max_seq = t.length();
        }
        return max_seq;
    }
}

