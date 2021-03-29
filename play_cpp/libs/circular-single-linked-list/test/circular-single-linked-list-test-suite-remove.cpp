#include "circular-single-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( circular_single_linked_list_suite_remove )

BOOST_AUTO_TEST_CASE( circular_single_linked_list_init )
{
	ds::csll list;
	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( circular_single_linked_list_remove_single_element )
{
	ds::csll list;
	list.add(1);
	BOOST_CHECK(list.size() == 1);

	BOOST_CHECK(list.remove() == 1);
	BOOST_CHECK(list.size() == 0);

}

BOOST_AUTO_TEST_CASE( circular_single_linked_list_remove_multiple_elements)
{
	ds::csll list;

	for (int i = 0; i < 10; i++)
		BOOST_CHECK(list.add(i) == 0);

	BOOST_CHECK(list.size() == 10);

	for (int i = 0; i < 10; i++)
		std::cout << list.remove() << " " << i;

	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()

