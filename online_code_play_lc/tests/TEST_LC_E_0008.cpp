#include <LC_E_0008.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0008 )

BOOST_AUTO_TEST_CASE( removeDuplicates_Case_1 )
{
	std::vector<int> v =
	{ 1, 1, 2 };
	int resarray[] =
	{ 1, 2 };
	int reslen = 2;

	BOOST_CHECK(lc::removeDuplicates(v) == reslen);

	for (int i = 0; i < reslen; i++)
		BOOST_CHECK(v[i] == resarray[i]);
}

BOOST_AUTO_TEST_CASE( removeDuplicates_Case_2 )
{
	std::vector<int> v =
	{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int resarray[] =
	{ 0, 1, 2, 3, 4 };
	int reslen = 5;

	BOOST_CHECK(lc::removeDuplicates(v) == reslen);

	for (int i = 0; i < reslen; i++)
		BOOST_CHECK(v[i] == resarray[i]);
}

BOOST_AUTO_TEST_SUITE_END()

