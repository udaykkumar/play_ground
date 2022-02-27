#include "double-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( dll_suite_print )

BOOST_AUTO_TEST_CASE( dll_print_empty_list )
{
	ds::dll list;
	list.print();
}

BOOST_AUTO_TEST_CASE( dll_print_single_element )
{
	ds::dll list;
	list.print();
}

BOOST_AUTO_TEST_CASE( dll_print_multiple_elements )
{
	ds::dll list;
	for (size_t i = 1; i <= 10; i++)
	{
		BOOST_CHECK(list.addHead(i) == 0);
		BOOST_CHECK(list.size() == i);
	}

	list.print();
}

BOOST_AUTO_TEST_SUITE_END()

