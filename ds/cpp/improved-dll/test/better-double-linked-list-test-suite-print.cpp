#include "better-double-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( betterdll_suite_print )

BOOST_AUTO_TEST_CASE( betterdll_print_empty_list )
{
	ds::betterdll list;
	list.print();
}

BOOST_AUTO_TEST_CASE( betterdll_print_single_element )
{
	ds::betterdll list;
	list.print();
}

BOOST_AUTO_TEST_CASE( betterdll_print_multiple_elements )
{
	ds::betterdll list;
	for (size_t i = 1; i <= 10; i++)
	{
		BOOST_CHECK(list.addHead(i) == 0);
		BOOST_CHECK(list.size() == i);
	}

	list.print();
}

BOOST_AUTO_TEST_SUITE_END()

