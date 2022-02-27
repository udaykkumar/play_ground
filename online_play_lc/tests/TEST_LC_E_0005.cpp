#include <LC_E_0005.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0005 )

BOOST_AUTO_TEST_CASE( longestCommonPrefix_Case_1 )
{
	std::vector<std::string> strs =
	{ "flower", "flow", "flight" };

	BOOST_CHECK( std::string("fl") == lc::longestCommonPrefix( strs ) )
	;
}

BOOST_AUTO_TEST_CASE( longestCommonPrefix_Case_2 )
{
	std::vector<std::string> strs =
			{ "flower", "flow", "flight", "asci", "ascii", "ascila", "flascila",
					"asbi" };

	BOOST_CHECK( std::string("") == lc::longestCommonPrefix( strs ) )
	;
}

BOOST_AUTO_TEST_CASE( longestCommonPrefix_Case_3 )
{
	std::vector<std::string> strs =
	{ "flower", "flow", "flight", "flayer", "flaaaack" };

	BOOST_CHECK( std::string("fl") == lc::longestCommonPrefix( strs ) )
	;
}

BOOST_AUTO_TEST_CASE( longestCommonPrefix_Case_4 )
{
	std::vector<std::string> strs =
	{ "dog", "racecar", "car" };
	BOOST_CHECK( std::string("") == lc::longestCommonPrefix( strs ) )
	;
}
BOOST_AUTO_TEST_CASE( longestCommonPrefix_Case_5 )
{
	std::vector<std::string> strs =
	{ "" };
	BOOST_CHECK( std::string("") == lc::longestCommonPrefix( strs ) )
	;
}
BOOST_AUTO_TEST_SUITE_END()

