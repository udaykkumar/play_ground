#include <LC_E_0003.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0003 )

BOOST_AUTO_TEST_CASE( isPalindrome_Method_3_2_Years_Ago_Case_1 )
{
	BOOST_CHECK(lc::isPalindrome_Method_3_2_Years_Ago(101) == true);
}

BOOST_AUTO_TEST_CASE( isPalindrome_Method_3_2_Years_Ago_Case_2 )
{
	BOOST_CHECK(lc::isPalindrome_Method_3_2_Years_Ago(1010) == false);
}

BOOST_AUTO_TEST_CASE( isPalindrome_Method_3_2_Years_Ago_Case_3 )
{
	BOOST_CHECK(lc::isPalindrome_Method_3_2_Years_Ago(101010101) == true);
}

BOOST_AUTO_TEST_CASE( isPalindrome_Method_3_2_Years_Ago_Case_4 )
{
	BOOST_CHECK(lc::isPalindrome_Method_3_2_Years_Ago(-121) == false);
}

BOOST_AUTO_TEST_CASE( isPalindrome_Method_3_2_Years_Ago_Case_5 )
{
	BOOST_CHECK(lc::isPalindrome_Method_3_2_Years_Ago(-101010101) == false);
}

BOOST_AUTO_TEST_SUITE_END()

