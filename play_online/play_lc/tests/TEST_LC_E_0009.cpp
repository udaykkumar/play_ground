#include <LC_E_0009.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0009 )

BOOST_AUTO_TEST_CASE( removeElement_Case_1 )
{
    std::vector<int> v  = {3,2,2,3};
    int     val         =  3;
    int     resarray[]  =  { 2, 2};
    int     reslen      =  2;

    BOOST_CHECK( lc::removeElement(v, val) == reslen);

    for( int i = 0 ; i < reslen; i ++ )
        BOOST_CHECK( v[i] == resarray[i]);
}

BOOST_AUTO_TEST_CASE( removeElement_Case_2 )
{
    std::vector<int> v  = {0,1,2,2,3,0,4,2};
    int     val         =  2;
    int     resarray[]  =  { 0,1,3,0,4};
    int     reslen      =  5;

    BOOST_CHECK( lc::removeElement(v, val) == reslen);

    for( int i = 0 ; i < reslen; i ++ )
        BOOST_CHECK( v[i] == resarray[i]);
}
BOOST_AUTO_TEST_SUITE_END()

