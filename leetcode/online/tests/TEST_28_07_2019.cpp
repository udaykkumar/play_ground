#include <28_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_28_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<int> v =
	{ 1, 3, 5, 3, 1, 3, 1, 5 };
	BOOST_CHECK(daily_interview::find_sequence(v) == 4);
}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::vector<int> v =
	{ 1, 3, 3, 3, 3, 3, 3, 3 };
	BOOST_CHECK(daily_interview::find_sequence(v) == 8);
}

BOOST_AUTO_TEST_CASE( Case_3 )
{
	std::vector<int> v =
	{ 1, 2, 1, 2, 1, 2, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1,
			2 };
	BOOST_CHECK(daily_interview::find_sequence(v) == 19);
}

BOOST_AUTO_TEST_SUITE_END()

