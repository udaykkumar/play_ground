#include <LC_E_0012.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0012 )

BOOST_AUTO_TEST_CASE( countAndSay_Case_1 )
{
    std::vector<std::string> resVector = 
    {
        "11",
        "21",
        "1211",
        "111221",
        "312211",
        "13112221",
        "1113213211"
    };

    for (size_t i = 0; i < resVector.size(); ++i)
    {
        BOOST_CHECK(lc::countAndSay(i+2) == resVector[i]);    
    }
    
}
BOOST_AUTO_TEST_SUITE_END()

