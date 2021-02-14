#include <27_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_27_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::string exp = "( 3 + ( 2 - 1 ) )";
	BOOST_CHECK( daily_interview::eval(exp) == 4 );
}


BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::string exp = "- ( 3 + ( 2 - 1 ) )";
	BOOST_CHECK( daily_interview::eval(exp) == -4 );
}


BOOST_AUTO_TEST_CASE( Case_3 )
{
	std::string exp = "1 + 2 * ( 3 + 5 ) - 1";
	BOOST_CHECK( daily_interview::eval(exp) == 16 );
}


BOOST_AUTO_TEST_SUITE_END()

