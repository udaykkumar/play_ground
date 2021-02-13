#include <15_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_15_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    std::vector<int> input = {1,3,3,5,7,8,9,9,9,15};
    int target = 9;
    std::pair<int, int> result = bounds(input, target);
    
    BOOST_CHECK(  result.first == 6 );
    BOOST_CHECK( result.second == 8 );
}


BOOST_AUTO_TEST_CASE( Case_2 )
{
    std::vector<int> input = {100, 150, 150, 153};
    int target = 150;
    std::pair<int, int> result = bounds(input, target);
    
    BOOST_CHECK(  result.first == 1 );
    BOOST_CHECK( result.second == 2 );
}

BOOST_AUTO_TEST_CASE( Case_3 )
{
    std::vector<int> input = {1,2,3,4,5,6,10};
    int target = 9;
    std::pair<int, int> result = bounds(input, target);
    
    BOOST_CHECK(  result.first == -1 );
    BOOST_CHECK( result.second == -1 );
}



BOOST_AUTO_TEST_SUITE_END()

