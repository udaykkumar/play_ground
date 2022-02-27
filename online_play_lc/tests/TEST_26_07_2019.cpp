#include <26_07_2019.hpp>
#include <boost/test/unit_test.hpp>

#include <iostream>
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_26_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::string s1 = "b";
	std::string s2 = "a";
	BOOST_CHECK(
			daily_interview::distance(s1, s2, s1.length(), s2.length()) == 1);
}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::string s1 = "b";
	std::string s2 = "ba";
	BOOST_CHECK(
			daily_interview::distance(s1, s2, s1.length(), s2.length()) == 1);
}

BOOST_AUTO_TEST_CASE( Case_3 )
{
	std::string s1 = "biting";
	std::string s2 = "sitting";
	BOOST_CHECK(
			daily_interview::distance(s1, s2, s1.length(), s2.length()) == 2);
}

BOOST_AUTO_TEST_CASE( Case_4 )
{
	std::string s1 = "sunday";
	std::string s2 = "saturday";
	BOOST_CHECK(
			daily_interview::distance(s1, s2, s1.length(), s2.length()) == 3);
}

BOOST_AUTO_TEST_SUITE_END()

