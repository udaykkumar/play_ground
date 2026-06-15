#include <03_08_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_03_08_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::string in = "..R...L..R.";
	std::string out = "..RR.LL..RR";
	BOOST_CHECK(daily_interview::falling_dominoes(in).compare(out) == 0);
}
BOOST_AUTO_TEST_SUITE_END()

