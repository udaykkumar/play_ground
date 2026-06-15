#include <LC_E_0016.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0016 )

BOOST_AUTO_TEST_CASE( addBinary_Case_1 )
{
	std::string s1 = "11";
	std::string s2 = "11";
	std::string s3 = "110";

	BOOST_TEST_MESSAGE(s1);
	BOOST_TEST_MESSAGE(s2);
	BOOST_TEST_MESSAGE(s3);
	BOOST_TEST_MESSAGE(lc::addBinary(s1, s2));
	BOOST_CHECK(lc::addBinary(s1, s2) == s3);
}

BOOST_AUTO_TEST_CASE( addBinary_Case_2 )
{
	std::string s1 = "1";
	std::string s2 = "1000";
	std::string s3 = "1001";

	BOOST_CHECK(lc::addBinary(s1, s2) == s3);
}

BOOST_AUTO_TEST_CASE( addBinary_Case_3 )
{
	std::string s1 = "1010";
	std::string s2 = "1011";
	std::string s3 = "10101";

	BOOST_CHECK(lc::addBinary(s1, s2) == s3);
}

BOOST_AUTO_TEST_SUITE_END()

