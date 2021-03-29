#include <infix_to_postfix.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_Infix_to_postfix )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    std::string in("1+2");
    std::string out("12+");
    BOOST_CHECK( out == bira::infix_to_post_fix(in) );
}


BOOST_AUTO_TEST_CASE( Case_2 )
{
    std::string  in("1+2+3+4");
    std::string out("1234+++");
    BOOST_CHECK( out == bira::infix_to_post_fix(in) );
}

BOOST_AUTO_TEST_SUITE_END()

