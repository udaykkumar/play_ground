#include <Chapter_3_selection_sort.h>
#include <Test_Utils.h>
#include <numeric>
#include <random>
#include <algorithm>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( Chapter_3_selection_sort_v1 )

BOOST_AUTO_TEST_CASE( selection_sort_random_vector )
{
	// IO
	const size_t iSz = 5;
	std::vector<int> iv(iSz), ov(iSz);
	generate_iv_ov(iv, ov);

	// Shuffle
	std::shuffle(iv.begin(), iv.end(), std::mt19937
	{ std::random_device
	{ }() });
	show_vector("if after shuffle", ov);

	// sort
	BOOST_TEST_MESSAGE(cphb::selection_sort_v1(iv));

	// Check
	BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}

BOOST_AUTO_TEST_CASE( selection_sort_sorted_vector )
{
	// IO
	const size_t iSz = 5;
	std::vector<int> iv(iSz), ov(iSz);
	generate_iv_ov(iv, ov);

	// Call
	BOOST_TEST_MESSAGE(cphb::selection_sort_v1(iv));

	// Check
	BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}

BOOST_AUTO_TEST_CASE( selection_sort_reverse_sorted_vector )
{
	// IO
	const size_t iSz = 5;
	std::vector<int> iv(iSz), ov(iSz);
	generate_iv_ov(iv, ov);

	std::sort(iv.begin(), iv.end(), std::greater<int>());
	show_vector("iv after greater sort", iv);

	// Call
	BOOST_TEST_MESSAGE(cphb::selection_sort_v1(iv));

	// Check
	BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}

BOOST_AUTO_TEST_CASE( selection_sort_all_n_vector )
{
	// IO
	const size_t iSz = 5;
	std::vector<int> iv(iSz), ov(iSz);

	std::fill(iv.begin(), iv.end(), 0);
	std::fill(ov.begin(), ov.end(), 0);

	// Call
	BOOST_TEST_MESSAGE(cphb::selection_sort_v1(iv));

	// Check
	BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}

BOOST_AUTO_TEST_SUITE_END()

