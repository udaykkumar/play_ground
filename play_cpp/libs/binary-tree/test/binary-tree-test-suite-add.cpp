#include "binary-tree.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( binary_tree_suite_add )

BOOST_AUTO_TEST_CASE( binary_tree_init )
{
    ds::binary_tree root;
    BOOST_CHECK( root.size() == 0 );
}

BOOST_AUTO_TEST_CASE( binary_tree_add_single_element )
{
    ds::binary_tree root;
    root.add(1);

    BOOST_CHECK( root.size() == 1 );
}

BOOST_AUTO_TEST_CASE( binary_tree_add_multiple_elements )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10; i ++ )
        root.add(i);

    BOOST_CHECK( root.size() == 10 );
}

BOOST_AUTO_TEST_CASE( binary_tree_add_duplicate_elements )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10; i ++ )
        root.add(i);

    for( int i = 0 ; i < 10; i ++ )
        root.add(i);

    BOOST_CHECK( root.size() == 10 );
}

BOOST_AUTO_TEST_SUITE_END()


