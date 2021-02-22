#include <moving_average.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_moving_average )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	lc::moving_average m(3);

	BOOST_CHECK( m.next(1)  == 1.00000 );
	BOOST_CHECK( m.next(10) == 5.50000 );
	BOOST_CHECK( m.next(3)  == 4.66667 );
	BOOST_CHECK( m.next(5)  == 6.00000 );

}
BOOST_AUTO_TEST_SUITE_END()

