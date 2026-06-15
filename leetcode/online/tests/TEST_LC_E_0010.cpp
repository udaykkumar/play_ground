#include <LC_E_0010.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0010 )

BOOST_AUTO_TEST_CASE( strStr_Case_1 )
{
	std::string s1 = "hello";
	std::string s2 = "ll";
	int res = 2;

	BOOST_CHECK(lc::strStr(s1, s2) == res);
}

BOOST_AUTO_TEST_CASE( strStr_Case_2 )
{
	std::string s1 = "aaaaa";
	std::string s2 = "baaa";
	int res = -1;

	BOOST_CHECK(lc::strStr(s1, s2) == res);
}

BOOST_AUTO_TEST_CASE( strStr_Case_3 )
{
	std::string s1 = "HelloThere";
	std::string s2 = "";
	int res = 0;

	BOOST_CHECK(lc::strStr(s1, s2) == res);
}

BOOST_AUTO_TEST_CASE( strStr_Case_4 )
{
	std::string s1 = "abb";
	std::string s2 = "abaaa";
	int res = -1;

	BOOST_CHECK(lc::strStr(s1, s2) == res);
}

BOOST_AUTO_TEST_CASE( strStr_Case_5 )
{
	std::string s1 = "abaaa";
	std::string s2 = "abaaa";
	int res = 0;

	BOOST_CHECK(lc::strStr(s1, s2) == res);
}
BOOST_AUTO_TEST_SUITE_END()

