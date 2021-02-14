#include "binary-search-tree.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( bst_suite_insert )

BOOST_AUTO_TEST_CASE( bst_init )
{
	ds::bst bst;

	int v = 1;

    bst.insert( v );
    bst.find( v );
    bst.remove( v );
    
}

BOOST_AUTO_TEST_SUITE_END()


