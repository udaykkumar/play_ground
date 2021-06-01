#include <insert_interval.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_insert_interval )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<std::vector<int> > intervals =
	{
	{ 1, 3 },
	{ 6, 9 } };
	std::vector<int> newInterval
	{ 2, 5 };

	std::vector<std::vector<int> > resInterval =
	{
	{ 1, 5 },
	{ 6, 9 } };
	auto result = lc::insert(intervals, newInterval);

//	BOOST_CHECK_EQUAL(result.size(), resInterval.size());
//	for (size_t i = 0; i < result.size(); ++i)
//	{
//		BOOST_CHECK_EQUAL(result[i][0], resInterval[i][0]);
//		BOOST_CHECK_EQUAL(result[i][1], resInterval[i][1]);
//	}
}
BOOST_AUTO_TEST_SUITE_END()

