#include "better-double-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( betterdll_suite_add )

BOOST_AUTO_TEST_CASE( betterdll_init )
{
	ds::betterdll list;
	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( betterdll_initial_list_should_be_empty )
{
	ds::betterdll list;
	BOOST_CHECK(list.isEmpty() == true);
}

BOOST_AUTO_TEST_CASE( betterdll_addHead_single_element )
{
	ds::betterdll list;
	BOOST_CHECK(list.addHead(1) == 0);

	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE( betterdll_addHead_multiple_elements )
{
	ds::betterdll list;
	for (size_t i = 1; i <= 10; i++)
	{
		BOOST_CHECK(list.addHead(i) == 0);
		BOOST_CHECK(list.size() == i);
	}

	BOOST_CHECK(list.size() == 10);
}

BOOST_AUTO_TEST_CASE( betterdll_addTail_single_element )
{
	ds::betterdll list;
	BOOST_CHECK(list.addTail(1) == 0);

	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE( betterdll_addTail_multiple_elements )
{
	ds::betterdll list;
	for (int i = 0; i < 10; i++)
		BOOST_CHECK(list.addTail(1) == 0);

	BOOST_CHECK(list.size() == 10);
}

BOOST_AUTO_TEST_SUITE_END()

