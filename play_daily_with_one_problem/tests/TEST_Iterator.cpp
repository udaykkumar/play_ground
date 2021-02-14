#include <Iterator.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_Iterator )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    bira::list l;
    BOOST_CHECK(l.size() == 0);

    for( int i = 1 ; i <= 10; i ++ ) 
    {
        l.add(i);
        BOOST_CHECK( l.size() == (size_t) i );
    }

    int index = 1;
    for( bira::list::iterator it = l.begin(); it != l.end(); ++ it , ++index )
    {
        BOOST_CHECK( index == it.get() );
    }
    
}


BOOST_AUTO_TEST_CASE( Case_2 )
{
    bira::list l;
    BOOST_CHECK(l.size() == 0);

    for( int i = 1 ; i <= 10; i ++ ) 
    {
        l.add(i);
        BOOST_CHECK( l.size() == (size_t) i );
    }

    l.reverse();
    int index = 10;
    for( bira::list::iterator it = l.begin(); it != l.end(); ++ it , --index )
    {
        BOOST_CHECK( index == it.get() );
    }
    
}

BOOST_AUTO_TEST_SUITE_END()

