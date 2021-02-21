#include <Hello_There.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_Hello_There )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	BOOST_CHECK( lc::say_hello() == "hello" );
}
BOOST_AUTO_TEST_SUITE_END()

