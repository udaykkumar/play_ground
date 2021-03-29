#include <LC_E_0015.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0015 )

BOOST_AUTO_TEST_CASE( plusOne_Case_1 )
{
    std::vector<int> iv = {1,2,3};
    std::vector<int> ov = {1,2,4};

    lc::plusOne(iv);
    for( size_t i = 0 ; i < iv.size(); i ++ )
        BOOST_CHECK( iv.at(i) == ov.at(i) );

}


BOOST_AUTO_TEST_CASE( plusOne_Case_2 )
{
    std::vector<int> iv = {4,3,2,1};
    std::vector<int> ov = {4,3,2,2};

    lc::plusOne(iv);
    for( size_t i = 0 ; i < iv.size(); i ++ )
        BOOST_CHECK( iv.at(i) == ov.at(i) );
    
}
BOOST_AUTO_TEST_SUITE_END()

