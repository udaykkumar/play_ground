#include "chapter_2.hxx"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( chapter_2_suite)
;

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_add_case_1 )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	BOOST_CHECK(list.size() == 10);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_add_case_2_add_duplicates )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	BOOST_CHECK(list.size() == 10);

	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	BOOST_CHECK(list.size() == 20);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_empty_size_is_0 )
{
	ctci6e::chapter2::list list;
	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_exists_success_case_1 )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	BOOST_CHECK(list.size() == 10);

	BOOST_CHECK(list.exists(5) == true);

}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_exists_failure_case_1 )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	BOOST_CHECK(list.size() == 10);

	BOOST_CHECK(list.exists(15) == false);

}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_exists_empty_list_always_false )
{
	ctci6e::chapter2::list list;
	BOOST_CHECK(list.exists(15) == false);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_remove_duplicates_case_1 )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	BOOST_CHECK(list.size() == 10);

	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	BOOST_CHECK(list.size() == 20);

	list.remove_dups();

	BOOST_CHECK(list.size() == 10);

}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_remove_duplicates_case_2 )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(1);
	}
	BOOST_CHECK(list.size() == 10);

	list.remove_dups();

	BOOST_CHECK(list.size() == 1);

}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_remove_duplicates_empty_list )
{
	ctci6e::chapter2::list list;

	BOOST_CHECK(list.size() == 0);
	list.remove_dups();
	BOOST_CHECK(list.size() == 0);

}

BOOST_AUTO_TEST_CASE( chapter_2_2_1_list_remove_duplicates_dont_change_list_if_no_duplicates )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	BOOST_CHECK(list.size() == 10);
	list.remove_dups();
	BOOST_CHECK(list.size() == 10);

}

BOOST_AUTO_TEST_CASE( chapter_2_2_2_list_return_kth_to_last_simple_1 )
{
	ctci6e::chapter2::list list, *new_list = NULL;

	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	BOOST_CHECK(list.size() == 10);

	new_list = list.return_kth_to_last(4);
	BOOST_CHECK(new_list != NULL);
	BOOST_CHECK(new_list->size() == 6);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_2_list_return_kth_to_last_simple_2 )
{
	ctci6e::chapter2::list list, *new_list = NULL;

	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	BOOST_CHECK(list.size() == 10);

	new_list = list.return_kth_to_last(0);
	BOOST_CHECK(new_list != NULL);
	BOOST_CHECK(new_list->size() == 10);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_2_list_return_kth_to_last_simple_3 )
{
	ctci6e::chapter2::list list, *new_list = NULL;

	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	BOOST_CHECK(list.size() == 10);

	new_list = list.return_kth_to_last(10);
	BOOST_CHECK(new_list == NULL);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_2_list_return_kth_to_last_simple_4 )
{
	ctci6e::chapter2::list list, *new_list = NULL;
	BOOST_CHECK(list.size() == 0);

	new_list = list.return_kth_to_last(10);
	BOOST_CHECK(new_list == NULL);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_3_list_delete_middle_node_simple_1 )
{
	ctci6e::chapter2::list list;

	for (int i = 1; i <= 5; i++)
	{
		list.append(i);
	}

	BOOST_CHECK(list.size() == 5);

	BOOST_CHECK(list.exists(3) == true);

	list.delete_middle_node();

	BOOST_CHECK(list.exists(3) == false);
	BOOST_CHECK(list.size() == 4);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_3_list_delete_middle_node_single_element_doesnt_do_anything )
{
	ctci6e::chapter2::list list;
	list.append(1);

	BOOST_CHECK(list.size() == 1);

	BOOST_CHECK(list.exists(1) == true);

	list.delete_middle_node();

	BOOST_CHECK(list.exists(1) == true);
	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_3_list_delete_middle_node_two_elements_doesnt_do_anything )
{
	ctci6e::chapter2::list list;
	list.append(1);
	list.append(2);

	BOOST_CHECK(list.size() == 2);

	BOOST_CHECK(list.exists(1) == true);

	list.delete_middle_node();

	BOOST_CHECK(list.exists(1) == true);
	BOOST_CHECK(list.size() == 2);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_3_list_delete_middle_node_empty_list_doesnt_do_anything )
{
	ctci6e::chapter2::list list;

	BOOST_CHECK(list.size() == 0);

	list.delete_middle_node();

	BOOST_CHECK(list.size() == 0);
}

BOOST_AUTO_TEST_CASE( chapter_2_2_4_list_partition_simple )
{
	ctci6e::chapter2::list list;
	list.add(1);
	list.add(2);
	list.add(4);
	list.add(5);
	list.add(3);

	list.show();
	list.partition(3);

	list.show();

}

BOOST_AUTO_TEST_CASE( chapter_2_2_4_list_partition_simple_case_2 )
{
	ctci6e::chapter2::list list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	list.show();

	list.partition(5);

	list.show();

}

BOOST_AUTO_TEST_CASE( chapter_2_2_5_list_sum_simple_case_1 )
{
	ctci6e::chapter2::list list1;

	list1.add(2);
	list1.add(3);
	list1.add(5);
	list1.show();

	list1.show();

}

BOOST_AUTO_TEST_SUITE_END();
