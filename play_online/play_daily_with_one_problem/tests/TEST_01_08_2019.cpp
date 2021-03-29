#include <01_08_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_01_08_2019 )

BOOST_AUTO_TEST_CASE( num_ways_Case_1 )
{
    BOOST_CHECK( daily_interview::num_ways(2,2) == 2);
}

BOOST_AUTO_TEST_CASE( num_ways_Case_2 )
{
    BOOST_CHECK( daily_interview::num_ways(3,3) == 6);
}


BOOST_AUTO_TEST_CASE( num_ways_better_Case_1 )
{
    BOOST_CHECK( daily_interview::num_ways_better(2,2) == 2);
}

BOOST_AUTO_TEST_CASE( num_ways_better_Case_2 )
{
    BOOST_CHECK( daily_interview::num_ways_better(3,3) == 6);
}


BOOST_AUTO_TEST_CASE( num_ways_even_better_Case_1 )
{
    BOOST_CHECK( daily_interview::num_ways_even_better(2,2) == 2);
}

BOOST_AUTO_TEST_CASE( num_ways_even_better_Case_2 )
{
    BOOST_CHECK( daily_interview::num_ways_even_better(3,3) == 6);
}
BOOST_AUTO_TEST_SUITE_END()

