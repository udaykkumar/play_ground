#include <LC_E_0013.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0013 )

BOOST_AUTO_TEST_CASE( maxSubArray_Case_1 )
{
	std::vector<int> v =
	{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int res = 6;

	BOOST_TEST_MESSAGE(lc::maxSubArray(v));
	BOOST_CHECK(lc::maxSubArray(v) == res);
}

BOOST_AUTO_TEST_CASE( maxSubArray_Case_2 )
{
	std::vector<int> v =
	{ 0, 0, 0, 0, -1, -1, 6 };
	int res = 6;

	BOOST_TEST_MESSAGE(lc::maxSubArray(v));
	BOOST_CHECK(lc::maxSubArray(v) == res);
}

BOOST_AUTO_TEST_CASE( maxSubArray_Case_3 )
{
	std::vector<int> v =
	{ 1, 2, 3, 4, -10, 25, 5, 10, -324, 1 };
	int res = 40;
	BOOST_TEST_MESSAGE(lc::maxSubArray(v));
	BOOST_CHECK(lc::maxSubArray(v) == res);
}
BOOST_AUTO_TEST_SUITE_END()

