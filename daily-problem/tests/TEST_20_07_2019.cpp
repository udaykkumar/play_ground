#include <20_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_20_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<int> arr = {13, 4, 7};
    BOOST_CHECK( daily_interview::can_it_be_made_non_decreasing(arr) == true );
}



BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::vector<int> arr = {13, 4, 1};
    BOOST_CHECK( daily_interview::can_it_be_made_non_decreasing(arr) == false );
}



BOOST_AUTO_TEST_CASE( Case_3 )
{
	std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 23};
    BOOST_CHECK( daily_interview::can_it_be_made_non_decreasing(arr) == true );
}


BOOST_AUTO_TEST_CASE( Case_4 )
{
	std::vector<int> arr = {10, 2, 23, 24, 35, 46, 57, 68, 79, 8, 0, 23};
    BOOST_CHECK( daily_interview::can_it_be_made_non_decreasing(arr) == false );
}


BOOST_AUTO_TEST_SUITE_END()

