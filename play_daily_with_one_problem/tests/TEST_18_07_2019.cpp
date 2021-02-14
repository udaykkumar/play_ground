#include <18_07_2019.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_18_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    std::vector<int> v = {4, 7, 1 , -3, 2};
    int 			 k = 5;
	BOOST_CHECK( daily_interview::two_sum_exists(v, k) == true);
}

BOOST_AUTO_TEST_CASE( Case_2 )
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,0};
    int 			 k = -1;
	BOOST_CHECK( daily_interview::two_sum_exists(v, k) == false );
}

BOOST_AUTO_TEST_CASE( Case_3 )
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,0,-1};
    int 			 k = 1;
	BOOST_CHECK( daily_interview::two_sum_exists(v, k) == true);
}


BOOST_AUTO_TEST_CASE( Case_4 )
{
    std::vector<int> v = {1, 1, 1, 1, 1, 1};
    int 			 k = 2;
	BOOST_CHECK( daily_interview::two_sum_exists(v, k) == true);
}



BOOST_AUTO_TEST_CASE( Case_5 )
{
    std::vector<int> v = {0, 0, 0 };
    int 			 k = 1;
	BOOST_CHECK( daily_interview::two_sum_exists(v, k) == false);
}


BOOST_AUTO_TEST_CASE( Case_6 )
{
    std::vector<int> v = {-1, 0, 0, 0, 0, 0, 0, 1};
    int 			 k = 0;
	BOOST_CHECK( daily_interview::two_sum_exists(v, k) == true);
}


BOOST_AUTO_TEST_SUITE_END()

