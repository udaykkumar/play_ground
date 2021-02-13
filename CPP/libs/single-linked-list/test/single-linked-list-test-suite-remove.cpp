#include "single-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( sll_suite_remove )

BOOST_AUTO_TEST_CASE( sll_init )
{
    ds::sll list;
    BOOST_CHECK( list.size() == 0 );
}

/* remove Head and family */
BOOST_AUTO_TEST_CASE( sll_removeHead_from_empty_is_minus_1 )
{
    ds::sll list;
    BOOST_CHECK( list.removeHead() == -1 );
}

BOOST_AUTO_TEST_CASE( sll_removeHead_with_single_element )
{
    ds::sll list;
    list.addHead(1);
    BOOST_CHECK( list.removeHead() == 1 );
    BOOST_CHECK( list.removeHead() == -1 );
}

BOOST_AUTO_TEST_CASE( sll_removeHead_with_multiple_elements )
{
    ds::sll list;
    for( int i = 0 ; i < 10; i ++ )
        list.addHead(i);

    for( int i = 9 ; i >= 0 ; i -- )
        BOOST_CHECK( list.removeHead() == i );

    BOOST_CHECK( list.removeHead() == -1 );
}
/* remove Tail and family */
BOOST_AUTO_TEST_CASE( sll_removeTail_from_empty_is_minus_1 )
{
    ds::sll list;
    BOOST_CHECK( list.removeTail() == -1 );
}

BOOST_AUTO_TEST_CASE( sll_removeTail_with_single_element )
{
    ds::sll list;
    list.addHead(1);
    BOOST_CHECK( list.removeTail() == 1 );
    BOOST_CHECK( list.removeTail() == -1 );
}

BOOST_AUTO_TEST_CASE( sll_removeTail_with_multiple_elements )
{
    ds::sll list;
    for( int i = 0 ; i < 10; i ++ )
        list.addTail(i);

    for( int i = 9 ; i >= 0; i -- )
        BOOST_CHECK( list.removeTail() == i );

    BOOST_CHECK( list.removeTail() == -1 );
}

BOOST_AUTO_TEST_CASE( sll_removeAtPosition_empty_list )
{
    ds::sll list;
    BOOST_CHECK( list.removeAtPosition(0) == -1 );
}

BOOST_AUTO_TEST_CASE( sll_removeAtPosition_single_element )
{
    ds::sll list;
        list.addHead(1);
    BOOST_CHECK( list.removeAtPosition(1) == 1 );
    BOOST_CHECK( list.removeAtPosition(1) == -1 );
    BOOST_CHECK( list.size() == 0 );
}

BOOST_AUTO_TEST_CASE( sll_removeAtPosition_random_position_in_list_with_multiple_elements )
{
    ds::sll list;
    for( int i = 0 ; i < 10; i ++ )
        list.addHead(i);
    BOOST_CHECK( list.removeAtPosition(5) == 5 );
    BOOST_CHECK( list.size() == 9 );
}

BOOST_AUTO_TEST_SUITE_END()


