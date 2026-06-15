#include "binary-tree.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( binary_tree_suite_delete )

BOOST_AUTO_TEST_CASE( binary_tree_init )
{
	ds::binary_tree root;
	BOOST_CHECK(root.size() == 0);
}

BOOST_AUTO_TEST_CASE( binary_tree_delete_from_tree_with_single_element )
{
	ds::binary_tree root;
	root.add(1);
	BOOST_CHECK(root.size() == 1);
	BOOST_CHECK(root.del(1) == 0);
	BOOST_CHECK(root.size() == 0);
}

BOOST_AUTO_TEST_CASE( binary_tree_delete_from_tree_with_multiple_elements_delete_leaf )
{
	ds::binary_tree root;
	for (size_t i = 1; i <= 10; i++)
	{
		root.add(i);
		BOOST_CHECK(root.size() == i);
	}

	for (size_t i = 10; i > 0; i--)
	{
		root.del(i);
		BOOST_CHECK(root.size() == i - 1);
	}

	BOOST_CHECK(root.size() == 0);
}

BOOST_AUTO_TEST_CASE( binary_tree_delete_from_tree_with_multiple_elements_delete_node_with_one_child_left )
{
	ds::binary_tree root;

	for (size_t i = 10; i > 0; i--)
		root.add(i);

	BOOST_CHECK(root.size() == 10);

	for (size_t i = 10; i > 0; i--)
	{
		root.display();
		root.del(i);
	}

	BOOST_CHECK(root.size() == 0);
}

BOOST_AUTO_TEST_CASE( binary_tree_delete_from_tree_with_multiple_elements_delete_node_with_one_child_right )
{
	ds::binary_tree root;

	for (size_t i = 0; i < 10; i++)
		root.add(i);

	BOOST_CHECK(root.size() == 10);

	for (size_t i = 0; i < 10; i++)
	{
		root.display();
		root.del(i);
	}

	BOOST_CHECK(root.size() == 0);
}

BOOST_AUTO_TEST_CASE( binary_tree_delete_from_tree_with_multiple_elements_randomly_placed )
{
	std::vector<int> v =
	{ 76, 43, 79, 33, 66, 11, 99, 1, 13, 0, 25, 52, 90, 101 };
	ds::binary_tree root;

	for (auto i : v)
		root.add(i);

	std::cout << " root.size() " << root.size() << " vector.size() " << v.size()
			<< std::endl;
	BOOST_CHECK(root.size() == v.size());
	root.display();

	root.del(43);
	root.display();

	BOOST_CHECK(root.size() == v.size() - 1);
}

BOOST_AUTO_TEST_SUITE_END()

