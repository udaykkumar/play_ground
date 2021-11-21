#include <14_11_2021.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_14_11_2021 )

BOOST_AUTO_TEST_CASE( find_pair_Case_1 )
{
	std::vector < int > v { 1, 2, 3, 4 ,5 ,6 };
	auto res = daily_interview::find_pair(v, 11);
	std::sort ( res.begin(), res.end() );
	int l1 = res[0];
	int l2 = res[1];

	BOOST_TEST_MESSAGE( " res[0] " << l1 << " res[1 " << l2 );
	BOOST_CHECK(res[0] == 5);
	BOOST_CHECK(res[1] == 6);

}

BOOST_AUTO_TEST_SUITE_END()

