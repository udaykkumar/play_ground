#include "binary-tree.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( binary_tree_suite_display )

BOOST_AUTO_TEST_CASE( binary_tree_display_default )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    root.display();
}


BOOST_AUTO_TEST_CASE( binary_tree_display_postorder )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    root.display( ds::binary_tree::POST_ORDER );
}


BOOST_AUTO_TEST_CASE( binary_tree_display_inorder )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    root.display( ds::binary_tree::IN_ORDER );
}


BOOST_AUTO_TEST_CASE( binary_tree_display_preorder )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    root.display( ds::binary_tree::PRE_ORDER);
}

BOOST_AUTO_TEST_SUITE_END()


