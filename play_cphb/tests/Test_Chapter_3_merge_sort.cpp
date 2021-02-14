#include <Chapter_3_merge_sort.h>
#include <Test_Utils.h>
#include <numeric>
#include <random>
#include <algorithm>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;


BOOST_AUTO_TEST_SUITE( Chapter_3_merge_sort_v1 )

BOOST_AUTO_TEST_CASE( merge_sort_random_vector )
{
    // IO
    const size_t iSz = 5;
    std::vector<int> iv(iSz), ov(iSz);
    generate_iv_ov(iv, ov);

    // Shuffle
	std::shuffle(iv.begin(), iv.end(), std::mt19937{
        std::random_device{}()});
	// sort
    show_vector( "Input ", iv );
    BOOST_TEST_MESSAGE( cphb::merge_sort_v1(iv) );

    // Check
    show_vector( "Expected ", ov );
    show_vector( "Got     ", iv );
    BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}


BOOST_AUTO_TEST_CASE( merge_sort_sorted_vector )
{
    // IO
    const size_t iSz = 5;
    std::vector<int> iv(iSz), ov(iSz);
    generate_iv_ov(iv, ov);

    // Call
    show_vector( "Input ", iv );
    BOOST_TEST_MESSAGE( cphb::merge_sort_v1(iv) );

    // Check
    show_vector( "Expected ", ov );
    show_vector( "Got     ", iv );
    BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}

BOOST_AUTO_TEST_CASE( merge_sort_reverse_sorted_vector )
{
    // IO
    const size_t iSz = 5;
    std::vector<int> iv(iSz), ov(iSz);
    generate_iv_ov(iv, ov);

    std::sort( iv.begin(), iv.end(), std::greater<int>());
	
    // Call
    show_vector( "Input ", iv );
    BOOST_TEST_MESSAGE ( cphb::merge_sort_v1(iv) );

    // Check
    show_vector( "Expected ", ov );
    show_vector( "Got     ", iv );
    BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}

BOOST_AUTO_TEST_CASE( merge_sort_all_n_vector )
{
    // IO
    const size_t iSz = 5;
    std::vector<int> iv(iSz), ov(iSz);

    std::fill(iv.begin(), iv.end(), 0);
    std::fill(ov.begin(), ov.end(), 0);

    // Call
    show_vector( "Input ", iv );
    BOOST_TEST_MESSAGE( cphb::merge_sort_v1(iv) );

    // Check
    show_vector( "Expected ", ov );
    show_vector( "Got     ", iv );
    BOOST_CHECK(std::equal(iv.begin(), iv.end(), ov.begin()));
}



BOOST_AUTO_TEST_SUITE_END()

