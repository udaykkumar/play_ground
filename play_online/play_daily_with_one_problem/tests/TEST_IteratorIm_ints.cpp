#include <IteratorIm.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_IteratorIm_ints )

BOOST_AUTO_TEST_CASE( Validate_List_Initial_List_size_to_be_zero )
{
	bira::list<int> intlist;
	BOOST_CHECK(intlist.size() == 0);
}

BOOST_AUTO_TEST_CASE( Validate_List_Add_Items_To_Back_Increases_The_Size )
{
	bira::list<int> intlist;
	for (int looper = 1; looper <= 10; looper++)
	{
		intlist.push_back(looper);
		BOOST_CHECK(intlist.size() == (size_t ) looper);
	}
	BOOST_CHECK(intlist.size() == 10);
}

BOOST_AUTO_TEST_CASE( Validate_List_Add_Items_To_Front_Increases_The_Size )
{
	bira::list<int> intlist;
	for (int looper = 1; looper <= 10; looper++)
	{
		intlist.push_front(looper);
		BOOST_CHECK(intlist.size() == (size_t ) looper);
	}
	BOOST_CHECK(intlist.size() == 10);
}

BOOST_AUTO_TEST_CASE( Validate_List_Iterate_through_list_after_push_back )
{
	int looper = 1;
	bira::list<int> intlist;

	for (looper = 1; looper <= 10; looper++)
		intlist.push_back(looper);

	looper = 1;
	for (bira::list<int>::iterator it = intlist.begin(); it != intlist.end();
			it++)
	{
		BOOST_CHECK(it.get() == looper++);
	}

	BOOST_CHECK(looper > 10);
}

BOOST_AUTO_TEST_CASE( Validate_List_Iterate_through_list_after_push_front )
{
	int looper = 1;
	bira::list<int> intlist;

	for (looper = 1; looper <= 10; looper++)
		intlist.push_front(looper);

	looper = 10;
	for (bira::list<int>::iterator it = intlist.begin(); it != intlist.end();
			it++)
		BOOST_CHECK(it.get() == looper--);

	BOOST_CHECK(looper < 1);
}

BOOST_AUTO_TEST_CASE( Validate_List_reverse )
{
	int looper = 1;
	bira::list<int> intlist;
	for (looper = 1; looper <= 10; looper++)
	{
		intlist.push_front(looper);
	}
	intlist.reverse();
	looper = 1;
	for (bira::list<int>::iterator it = intlist.begin(); it != intlist.end();
			it++)
		BOOST_CHECK(it.get() == looper++);
}

BOOST_AUTO_TEST_CASE( Validate_front_on_push_front )
{
	int looper = 1;
	bira::list<int> intlist;
	for (looper = 1; looper <= 10; looper++)
	{
		intlist.push_front(looper);
		BOOST_CHECK( intlist.front() == looper )
		;
	}
	BOOST_CHECK( intlist.front() == (looper-1) )
	;
}

BOOST_AUTO_TEST_CASE( Validate_front_on_push_back )
{
	int looper = 1;
	bira::list<int> intlist;
	for (looper = 1; looper <= 10; looper++)
	{
		intlist.push_back(looper);
		BOOST_CHECK(intlist.front() == 1);
	}
	BOOST_CHECK(intlist.front() == 1);
}

BOOST_AUTO_TEST_CASE( Validate_back_on_push_front )
{
	int looper = 1;
	bira::list<int> intlist;
	for (looper = 1; looper <= 10; looper++)
	{
		intlist.push_front(looper);
		BOOST_CHECK(intlist.back() == 1);
	}
	BOOST_CHECK(intlist.back() == 1);
}

BOOST_AUTO_TEST_CASE( Validate_back_on_push_back )
{
	int looper = 1;
	bira::list<int> intlist;
	for (looper = 1; looper <= 10; looper++)
	{
		intlist.push_back(looper);
		BOOST_CHECK(intlist.back() == looper);
	}
	BOOST_CHECK(intlist.back() == (looper - 1));
}

BOOST_AUTO_TEST_CASE( Validate_pop_front_on_push_front )
{
	int looper = 1;
	bira::list<int> intlist;
	for (looper = 1; looper <= 10; looper++)
	{
		intlist.push_front(looper);
	}

	for (looper = 10; looper > 0; looper--)
	{
		BOOST_CHECK(looper == intlist.front());
		intlist.pop_front();
	}
	BOOST_CHECK(intlist.size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()

