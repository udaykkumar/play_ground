#include <LC_E_0001.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0001 )

BOOST_AUTO_TEST_CASE( twoSum_method_2_Case_1 )
{
	std::vector<int> v
	{ 2, 7, 11, 15 };
	int target = 9;

	auto res = lc::twoSum_method_2(v, target);

	BOOST_CHECK(res[0] == 0);
	BOOST_CHECK(res[1] == 1);

}

BOOST_AUTO_TEST_CASE( twoSum_method_2_Case_2 )
{
	std::vector<int> v
	{ 2, 7, 11, 15, 23, 99, 156, 126, 11 };
	int target = 1;

	auto res = lc::twoSum_method_2(v, target);

	BOOST_CHECK(res[0] == -1);
	BOOST_CHECK(res[1] == -1);

}

BOOST_AUTO_TEST_CASE( twoSum_method_2_Case_3 )
{
	std::vector<int> v
	{ 2, 7, 11, 15, 23, 99, 156, 126, 17 };
	int target = 143;

	auto res = lc::twoSum_method_2(v, target);

	BOOST_CHECK(res[0] == 7);
	BOOST_CHECK(res[1] == 8);

}

BOOST_AUTO_TEST_CASE( twoSum_method_2_Case_4 )
{
	int target = 27;
	std::vector<int> v;

	for (int i = 0; i < 10000; i++)
		v.push_back(0);

	v.push_back(13);
	v.push_back(14);

	auto res = lc::twoSum_method_2(v, target);

	BOOST_CHECK(res[0] == 10000);
	BOOST_CHECK(res[1] == 10001);

}

BOOST_AUTO_TEST_CASE( twoSum_method_2_Case_5 )
{
	std::vector<int> v
	{ 3, 2, 4 };
	int target = 6;

	auto res = lc::twoSum_method_2(v, target);

	BOOST_CHECK(res[0] == 1);
	BOOST_CHECK(res[1] == 2);

}
BOOST_AUTO_TEST_SUITE_END()

