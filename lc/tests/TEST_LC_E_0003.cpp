#include <LC_E_0003.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0003 )

BOOST_AUTO_TEST_CASE( isPalindrome_Case_1 )
{
    BOOST_CHECK( lc::isPalindrome(101) == true );
}


BOOST_AUTO_TEST_CASE( isPalindrome_Case_2 )
{
    BOOST_CHECK( lc::isPalindrome(1010) == false );
}

BOOST_AUTO_TEST_CASE( isPalindrome_Case_3 )
{
    BOOST_CHECK( lc::isPalindrome(101010101) == true );
}


BOOST_AUTO_TEST_CASE( isPalindrome_Case_4 )
{
    BOOST_CHECK( lc::isPalindrome(-121) == false );
}

BOOST_AUTO_TEST_CASE( isPalindrome_Case_5 )
{
    BOOST_CHECK( lc::isPalindrome(-101010101) == false );
}


BOOST_AUTO_TEST_SUITE_END()

