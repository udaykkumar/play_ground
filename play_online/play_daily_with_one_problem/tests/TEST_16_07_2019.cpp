#include <16_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_16_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	list l;
	BOOST_CHECK(l.size() == 0);

	for (size_t i = 1; i <= 10; i++)
	{
		l.add(i);
		BOOST_CHECK(l.size() == i);
	}

	/*
	 std::cout << "Original List : " ;
	 l.traverse();
	 */

	// l.reverse();
	/*
	 std::cout << "Reversed List : " ;
	 l.traverse();
	 */

	/* Nothing much to be done yet.. thats a shame */
	BOOST_CHECK(l.size() == 10);
}

BOOST_AUTO_TEST_SUITE_END()

