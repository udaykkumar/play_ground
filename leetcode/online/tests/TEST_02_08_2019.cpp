#include <02_08_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_02_08_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	daily_interview::list l1, l2;

	l1.add(1);
	l1.add(10);
	l1.add(20);
	l1.add(30);
	l1.add(40);
	l2.add(2);
	l2.add(20);
	l2.add(35);
	l2.add(45);
	l2.add(60);

	BOOST_CHECK(daily_interview::intersection(l1, l2) == 20);

}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	daily_interview::list l1, l2;

	for (size_t i = 0; i <= 100; i++)
		l1.add(i);

	for (size_t i = 200; i > 99; i--)
		l2.add(i);

	BOOST_CHECK(daily_interview::intersection(l1, l2) == 100);

}

BOOST_AUTO_TEST_CASE( Case_3 )
{
	daily_interview::list l1, l2;

	for (size_t i = 0; i < 100000; i++)
		l1.add(i);

	for (size_t i = 99999; i < 1000000; i++)
		l2.add(i);

	BOOST_CHECK(daily_interview::intersection(l1, l2) == 99999);

}
BOOST_AUTO_TEST_SUITE_END()

