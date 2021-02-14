#include <LC_E_0020.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0020 )

BOOST_AUTO_TEST_CASE( merge_Case_1 )
{
    std::vector<int> n1 = {1,2,3};
    std::vector<int> n2 = {2,5,6};
    std::vector<int>  n = {1,2,2,3,5,6};

    n1.resize(6);

    lc::merge( n1, 3, n2, 3 );

    for( int i = 0 ; i < 6 ; i ++ ){
        BOOST_CHECK( n1[i] == n[i] );
    }

}
BOOST_AUTO_TEST_SUITE_END()

