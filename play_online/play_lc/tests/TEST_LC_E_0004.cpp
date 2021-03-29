#include <LC_E_0004.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0004 )

BOOST_AUTO_TEST_CASE( romanToInt_Case_1 )
{
    BOOST_CHECK( lc::romanToInt( std::string("III") ) == 3 );
}

BOOST_AUTO_TEST_CASE( romanToInt_Case_2 )
{
    BOOST_CHECK( lc::romanToInt( std::string("I") ) == 1 );
}


BOOST_AUTO_TEST_CASE( romanToInt_Case_3 )
{
    BOOST_CHECK( lc::romanToInt( std::string("IV") ) == 4 );
}


BOOST_AUTO_TEST_CASE( romanToInt_Case_4 )
{
    BOOST_CHECK( lc::romanToInt( std::string("XIV") ) == 14 );
}



BOOST_AUTO_TEST_CASE( romanToInt_Case_5 )
{
    BOOST_CHECK( lc::romanToInt( std::string("XVI") ) == 16 );
}


BOOST_AUTO_TEST_CASE( romanToInt_Case_6 )
{
    BOOST_CHECK( lc::romanToInt( std::string("MCMXCIV") ) == 1994 );
}

BOOST_AUTO_TEST_SUITE_END()

