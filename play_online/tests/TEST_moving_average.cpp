#include <moving_average.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_moving_average )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	lc::moving_average m(3);

	double lhs1 = m.next(1);
	double lhs2 = m.next(10);
	double lhs3 = m.next(3);
	double lhs4 = m.next(5);

	double rhs1 = 1.00000;
	double rhs2 = 5.50000;
	double rhs3 = 4.66667;
	double rhs4 = 6.00000;

	BOOST_CHECK((int ) lhs1 == (int ) rhs1);
	BOOST_CHECK((int ) lhs2 == (int ) rhs2);
	BOOST_CHECK((int ) lhs3 == (int ) rhs3);
	BOOST_CHECK((int ) lhs4 == (int ) rhs4);

}
BOOST_AUTO_TEST_SUITE_END()

