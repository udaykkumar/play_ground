#include <LC_E_0014.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0014 )

BOOST_AUTO_TEST_CASE( lengthOfLastWord_Case_1 )
{
    BOOST_CHECK(lc::lengthOfLastWord("Hello World") == 5 );
    BOOST_CHECK(lc::lengthOfLastWord("") == 0 );
    BOOST_CHECK(lc::lengthOfLastWord("ther are a number of sentences that end with an exclamation !") == 1 );
    BOOST_CHECK(lc::lengthOfLastWord("the size of ! is actually 1") == 1 );
    BOOST_CHECK(lc::lengthOfLastWord("1") == 1 );
    BOOST_CHECK(lc::lengthOfLastWord("1 ") == 1 );
    BOOST_CHECK(lc::lengthOfLastWord("     ") == 0);

}
BOOST_AUTO_TEST_SUITE_END()

