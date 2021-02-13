#include <31_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_31_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 , * disabled() )
{
	std::vector<size_t> v = {2, 3, 1, 2, 4, 3} ;
	BOOST_CHECK( daily_interview::min_sub_array_len(v, 7) == 2);
}


BOOST_AUTO_TEST_SUITE_END()

