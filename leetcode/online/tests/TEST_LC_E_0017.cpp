#include <LC_E_0017.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0017 )

BOOST_AUTO_TEST_CASE( mySqrt_Case_1 )
{
	BOOST_CHECK(lc::mySqrt(4) == 2);
	BOOST_CHECK(lc::mySqrt(100) == 10);
	BOOST_CHECK(lc::mySqrt(8) == 2);
}
BOOST_AUTO_TEST_SUITE_END()

