#include "single-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( sll_suite_add )

BOOST_AUTO_TEST_CASE( sll_init )
{
	ds::sll list;
	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( sll_initial_list_should_be_empty )
{
	ds::sll list;
	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( sll_addHead_single_element )
{
	ds::sll list;
	BOOST_CHECK(list.addHead(1) == 0);

	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE( sll_addHead_multiple_elements )
{
	ds::sll list;
	for (size_t i = 1; i <= 10; i++)
	{
		BOOST_CHECK(list.addHead(i) == 0);
		BOOST_CHECK(list.size() == i);
	}

	BOOST_CHECK(list.size() == 10);
}

BOOST_AUTO_TEST_CASE( sll_addTail_single_element )
{
	ds::sll list;
	BOOST_CHECK(list.addTail(1) == 0);

	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE( sll_addTail_multiple_elements )
{
	ds::sll list;
	for (int i = 0; i < 10; i++)
		BOOST_CHECK(list.addTail(1) == 0);

	BOOST_CHECK(list.size() == 10);
}

BOOST_AUTO_TEST_CASE( sll_get_single_element )
{
	ds::sll list;
	list.addHead(1);

	BOOST_CHECK(list.size() == 1);
	BOOST_CHECK(list.get(1) == 1);
}

BOOST_AUTO_TEST_CASE( sll_get_random_element )
{
	ds::sll list;
	for (int i = 0; i < 10; i++)
		list.addHead(i);

	BOOST_CHECK(list.size() == 10);
	std::cout << " list.get(5) " << list.get(5) << std::endl;
	BOOST_CHECK(list.get(5) == 5);
}

BOOST_AUTO_TEST_CASE( sll_get_non_existent_element )
{
	ds::sll list;
	for (int i = 0; i < 10; i++)
		list.addHead(i);

	BOOST_CHECK(list.size() == 10);
	std::cout << " list.get(15) " << list.get(5) << std::endl;
	BOOST_CHECK(list.get(15) == -1);
}

BOOST_AUTO_TEST_CASE( sll_get_empty_list )
{
	ds::sll list;
	std::cout << " list.get(5) " << list.get(5) << std::endl;
	BOOST_CHECK(list.get(5) == -1);
}

BOOST_AUTO_TEST_CASE( sll_addAfterPosition_Empty_List )
{
	ds::sll list;
	BOOST_CHECK(list.size() == 0);
	list.addAfterPosition(200, 5);
	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE( sll_addAfterPosition_Some_Valid_Radmon_Position )
{
	ds::sll list;
	for (int i = 0; i < 10; i++)
		BOOST_CHECK(list.addTail(i) == 0);

	BOOST_CHECK(list.size() == 10);

	list.addAfterPosition(200, 5);
	BOOST_CHECK(list.get(6) == 200);

	BOOST_CHECK(list.size() == 11);
}

BOOST_AUTO_TEST_CASE( sll_addBeforePosition_Empty_List )
{
	ds::sll list;
	BOOST_CHECK(list.size() == 0);
	list.addBeforePosition(200, 5);
	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE( sll_addBeforePosition_Some_Valid_Radmon_Position )
{
	ds::sll list;
	for (int i = 0; i < 10; i++)
		BOOST_CHECK(list.addTail(i) == 0);

	BOOST_CHECK(list.size() == 10);

	list.addBeforePosition(200, 5);
	BOOST_CHECK(list.get(5) == 200);

	BOOST_CHECK(list.size() == 11);
}

BOOST_AUTO_TEST_CASE( sll_appendList_empty_list_to_empty_list )
{
	ds::sll list1;
	ds::sll list2;
	list1.appendList(list2);

	BOOST_CHECK(list1.size() == 0);
}

BOOST_AUTO_TEST_CASE( sll_appendList_non_empty_list_to_empty_list )
{
	ds::sll list1;
	ds::sll list2;
	for (int i = 0; i < 10; i++)
		list2.addHead(i);

	list1.appendList(list2);

	BOOST_CHECK(list1.size() == 10);
}

BOOST_AUTO_TEST_CASE( sll_appendList_non_empty_list_to_non_empty_list )
{
	ds::sll list1;
	ds::sll list2;
	for (int i = 0; i < 10; i++)
	{
		list2.addHead(i);
		list1.addHead(i);
	}

	list1.appendList(list2);

	BOOST_CHECK(list1.size() == 20);
}
BOOST_AUTO_TEST_SUITE_END()

