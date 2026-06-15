#include <LC_E_0006.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0006 )

BOOST_AUTO_TEST_CASE( isValid_Case_1 )
{
	BOOST_CHECK(lc::isValid("()[]{}") == true);
}

BOOST_AUTO_TEST_CASE( isValid_Case_2 )
{
	BOOST_CHECK(lc::isValid("()") == true);
}

BOOST_AUTO_TEST_CASE( isValid_Case_3 )
{
	BOOST_CHECK(lc::isValid("}{") == false);
}

BOOST_AUTO_TEST_CASE( isValid_Case_4 )
{
	BOOST_CHECK(lc::isValid("[(})]") == false);
}

BOOST_AUTO_TEST_CASE( isValid_Case_5 )
{
	BOOST_CHECK(lc::isValid("[(})]") == false);
}

BOOST_AUTO_TEST_CASE( isValid_Case_6 )
{
	BOOST_CHECK(lc::isValid("[") == false);
}

BOOST_AUTO_TEST_SUITE_END()

