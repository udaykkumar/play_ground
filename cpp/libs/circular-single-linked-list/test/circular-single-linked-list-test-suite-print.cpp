#include "circular-single-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( circular_single_linked_list_suite_print )

BOOST_AUTO_TEST_CASE( circular_single_linked_list_init )
{
    ds::csll list;
    BOOST_CHECK( list.size() == 0 );
}

BOOST_AUTO_TEST_CASE( circular_single_linked_list_print_single_element )
{
    ds::csll list;
    list.add(1);
    BOOST_CHECK( list.size() == 1 );
    list.print();

}

BOOST_AUTO_TEST_CASE( circular_single_linked_list_print_multiple_elements )
{
    ds::csll list;

    for( int i = 0 ; i < 10 ; i ++ )
        BOOST_CHECK( list.add(i) == 0 );

    BOOST_CHECK( list.size() == 10 );
    list.print();    
}


BOOST_AUTO_TEST_SUITE_END()


