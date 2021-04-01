#include <LC_E_0018.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0018 )

BOOST_AUTO_TEST_CASE( climbStairs_Case_1 )
{
	BOOST_CHECK(lc::climbStairs(2) == 2);
	BOOST_CHECK(lc::climbStairs(3) == 3);
}

BOOST_AUTO_TEST_CASE( climbStairs_Method_2_Case_1 )
{
	BOOST_CHECK(lc::climbStairs_Method_2(2) == 2);
	BOOST_CHECK(lc::climbStairs_Method_2(3) == 3);
}
BOOST_AUTO_TEST_SUITE_END()

