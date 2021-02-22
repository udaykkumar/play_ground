#include <two_sum.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_two_sum )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector< int > input = {2,7,11,15};
	int target = 9;
	
	std::vector< int > out   = {0,1};
	std::vector< int > res   = lc::two_sum(input, target);

	BOOST_CHECK( out[0] == res[0] and out[1] == res[1] );
}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::vector< int > input = {1,2,3,4,5,6,7,8};
	int target = 9;
	
	std::vector< int > out   = {0,7};
	std::vector< int > res   = lc::two_sum(input, target);

	BOOST_CHECK( out[0] == res[0] and out[1] == res[1] );
}

BOOST_AUTO_TEST_SUITE_END()

