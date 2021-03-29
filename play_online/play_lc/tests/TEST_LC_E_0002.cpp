#include <LC_E_0002.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_002 )

BOOST_AUTO_TEST_CASE( reverse_Case_1 )
{
    BOOST_CHECK( lc::reverse(123) == 321 );
    BOOST_CHECK( lc::reverse(-123) == -321 );
}

BOOST_AUTO_TEST_CASE( reverse_Case_2 )
{
    BOOST_CHECK( lc::reverse(1111) == 1111 );
}

BOOST_AUTO_TEST_CASE( reverse_Case_3 )
{
    BOOST_CHECK( lc::reverse(0) == 0 );
}


BOOST_AUTO_TEST_CASE( reverse_Case_4 )
{
    BOOST_CHECK( lc::reverse(10) == 1 );
}


BOOST_AUTO_TEST_CASE( reverse_Case_5 )
{
    BOOST_CHECK( lc::reverse(101) == 101 );
}


BOOST_AUTO_TEST_CASE( reverse_Case_6 )
{
    BOOST_CHECK( lc::reverse(9) == 9 );
}

BOOST_AUTO_TEST_CASE( reverse_Case_7 )
{
    BOOST_CHECK( lc::reverse(1534236469) == 0 );
}

BOOST_AUTO_TEST_CASE( reverse_Case_8 )
{
    BOOST_CHECK( lc::reverse(-2147483412) == -2143847412 );
}



BOOST_AUTO_TEST_SUITE_END()

