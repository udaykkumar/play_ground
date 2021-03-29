#include <17_07_2019.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_17_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    std::vector<int> v = {3, 3, 2, 1, 3, 2, 1};
    std::vector<int> r = {1, 1, 2, 2, 3, 3, 3};

    daily_bira::dose d(v);

    d.sort();

    std::vector<int>::iterator rIt = r.begin();
    for( std::vector<int>::iterator it = d.get().begin() ; it != d.get().end(); it ++,  rIt ++ )
    {
        BOOST_CHECK( *it == *rIt );
    }
    
}



BOOST_AUTO_TEST_CASE( Case_2 )
{
    std::vector<int> v = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 1, 1, 1, 1};
    std::vector<int> r = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3};

    daily_bira::dose d(v);

    d.sort();

    std::vector<int>::iterator rIt = r.begin();
    for( std::vector<int>::iterator it = d.get().begin() ; it != d.get().end(); it ++,  rIt ++ )
    {
        BOOST_CHECK( *it == *rIt );
    }
    
}
BOOST_AUTO_TEST_SUITE_END()

