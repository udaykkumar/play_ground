#include <LC_E_0011.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0011 )

BOOST_AUTO_TEST_CASE( searchInsert_Case_1 )
{
	std::vector<std::vector<int> > inputset_arg1 =
	{
	{ 1, 3, 5, 6 },
	{ 1, 3, 5, 6 },
	{ 1, 3, 5, 6 },
	{ 1, 3, 5, 6 } };

	std::vector<int> inputset_arg2 =
	{ 5, 2, 7, 0 };

	std::vector<int> outputset =
	{ 2, 1, 4, 0 };

	for (size_t i = 0; i < inputset_arg1.size(); i++)
	{
		BOOST_CHECK(
				lc::searchInsert(inputset_arg1[i], inputset_arg2[i])
						== outputset[i]);
	}

}
BOOST_AUTO_TEST_SUITE_END()

