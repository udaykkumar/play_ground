#include "double-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( dll_suite_add )

BOOST_AUTO_TEST_CASE( dll_init )
{
    ds::dll list;
    BOOST_CHECK( list.size() == 0 );
}

BOOST_AUTO_TEST_CASE( dll_initial_list_should_be_empty )
{
    ds::dll list;
    BOOST_CHECK( list.isEmpty() == true );
}

BOOST_AUTO_TEST_CASE( dll_addHead_single_element )
{
    ds::dll list;
    BOOST_CHECK( list.addHead(1) == 0 );

    BOOST_CHECK( list.size() == 1 );
}

BOOST_AUTO_TEST_CASE( dll_addHead_multiple_elements )
{
    ds::dll list;
    for( size_t i = 1; i <= 10 ; i ++ )
    {
        BOOST_CHECK( list.addHead(i) ==  0 );
        BOOST_CHECK( list.size() == i );
    }

    BOOST_CHECK( list.size() == 10 );
}

 BOOST_AUTO_TEST_CASE( dll_addTail_single_element )
 {
     ds::dll list;
     BOOST_CHECK( list.addTail(1) == 0 );

     BOOST_CHECK( list.size() == 1 );
 }


 BOOST_AUTO_TEST_CASE( dll_addTail_multiple_elements )
 {
     ds::dll list;
     for( int i = 0 ; i < 10 ; i ++ )
        BOOST_CHECK( list.addTail(1) == 0 );

     BOOST_CHECK( list.size() == 10 );
 }

 

BOOST_AUTO_TEST_SUITE_END()


