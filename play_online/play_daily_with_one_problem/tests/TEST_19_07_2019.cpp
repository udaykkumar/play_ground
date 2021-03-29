#include <19_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_19_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<int> input =
	{ 4, 3, 2, 4, 1, 3, 2 };
	int target = 1;
	int result = daily_interview::non_duplicate_im(input);

	BOOST_CHECK(result == target);

}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::vector<int> input =
	{ 4, 3, 2, 4, 1, 3, 2 };
	int target = 1;
	int result = daily_interview::non_duplicate(input);

	BOOST_CHECK(result == target);

}

BOOST_AUTO_TEST_SUITE_END()

