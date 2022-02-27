#include "single-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( sll_suite_print )

BOOST_AUTO_TEST_CASE( sll_init )
{
	ds::sll list;
	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( sll_initial_list_print_is_empty )
{
	ds::sll list;
	list.print();
	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( sll_print_with_lots_of_elements )
{
	ds::sll list;
	for (size_t i = 1; i <= 10; i++)
	{
		BOOST_CHECK(list.addHead(i) == 0);
		BOOST_CHECK(list.size() == i);
	}

	BOOST_CHECK(list.size() == 10);
	list.print();
}

BOOST_AUTO_TEST_SUITE_END()

