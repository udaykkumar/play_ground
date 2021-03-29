#include <shared_ptr_demo.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_shared_ptr_demo )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    daily_interview::shared s1;
    size_t i = 1 ;
    for(  ; i < 100; i ++ )
    {
        s1.put(i);
        BOOST_CHECK(s1.size() == i);
    }

    std::cout << s1;

    daily_interview::shared s2;
    for(  ; i < 1000; i ++ )
    {
        s2.put(i);
        BOOST_CHECK(s1.size() == i);
    }

    std::cout << s2;


}
BOOST_AUTO_TEST_SUITE_END()

