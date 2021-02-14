#include "binary-tree.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( binary_tree_suite_add )

BOOST_AUTO_TEST_CASE( binary_tree_find )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    for( int i = 0 ; i < 10 ; i += 2 )
        BOOST_CHECK( root.find(i) == i );
}

BOOST_AUTO_TEST_CASE( binary_tree_find_empty_list_returns_minus_1 )
{
    ds::binary_tree root;
        BOOST_CHECK( root.find(0) == -1 );
}

BOOST_AUTO_TEST_CASE( binary_tree_find_non_existent_element_returns_minus_1 )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    BOOST_CHECK( root.find(11) == -1 );
}

BOOST_AUTO_TEST_CASE( binary_tree_find_minimum )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    BOOST_CHECK( root.findmin() == 0 );
}

BOOST_AUTO_TEST_CASE( binary_tree_find_min_empty_returns_minus_1 )
{
    ds::binary_tree root;
    BOOST_CHECK( root.findmin() == -1 );
}

BOOST_AUTO_TEST_CASE( binary_tree_find_max )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ )
        root.add(i);

    BOOST_CHECK( root.findmax() == 9 );
}

BOOST_AUTO_TEST_CASE( binary_tree_find_max_empty_returns_minus_1 )
{
    ds::binary_tree root;
    BOOST_CHECK( root.findmax() == -1 );
}



BOOST_AUTO_TEST_CASE( binary_tree_find_min_max )
{
    ds::binary_tree root;
    for( int i = 0 ; i < 10 ; i ++ ){
        root.add(i);
    }

    BOOST_CHECK( root.findmax() == 9 );
    BOOST_CHECK( root.findmin() == 0 );

}

BOOST_AUTO_TEST_CASE( binary_tree_find_min_max_from_random_data )
{
    ds::binary_tree root;
    std::vector<int> random_data = { 67, 24, 16, 9, 900, 1, 5467, 55, 123, 1231, 1313 ,13, 44, 454 };
    for( auto data : random_data) {
        root.add(data);
    }

    BOOST_CHECK( root.findmax() == 5467 );
    BOOST_CHECK( root.findmin() == 1 );

}


BOOST_AUTO_TEST_CASE( binary_tree_find_random_data )
{
    ds::binary_tree root;
    std::vector<int> random_data = { 67, 24, 16, 9, 900, 1, 5467, 55, 123, 1231, 1313 ,13, 44, 454 };
    for( auto data : random_data) {
        root.add(data);
    }

    
    for( auto data : random_data) {
        BOOST_CHECK( root.find(data) == data );
    }
}

BOOST_AUTO_TEST_SUITE_END()


