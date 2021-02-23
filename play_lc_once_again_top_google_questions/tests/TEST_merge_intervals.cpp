#include <merge_intervals.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_merge_intervals )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector< std::vector<int> > intervals(
		{
			{1,3},
			{2,6},
			{8,10}, 
			{15,18}
		});
	
	std::vector< std::vector<int> > result(
		{
			{1,6},
			{8,10}, 
			{15,18}
		});


	auto res = lc::merge(intervals);

	for ( int i = 0 ; i < res.size() ; ++ i)
	{
		BOOST_CHECK(res[i][0] == result[i][0]);
		BOOST_CHECK(res[i][1] == result[i][1]);
	}
}


BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::vector< std::vector<int> > intervals(
		{
			{1,4},
			{4,5}
		});
	
	std::vector< std::vector<int> > result(
		{
			{1,5}
		});


	auto res = lc::merge(intervals);

	for ( int i = 0 ; i < res.size() ; ++ i)
	{
		BOOST_CHECK(res[i][0] == result[i][0]);
		BOOST_CHECK(res[i][1] == result[i][1]);
	}
}


BOOST_AUTO_TEST_CASE( Case_3 )
{
	std::vector< std::vector<int> > intervals(
		{
			{1,4},
			{5,6}
		});
	
	std::vector< std::vector<int> > result(
		{
			{1,4},
			{5,6}
		});


	auto res = lc::merge(intervals);

	for ( int i = 0 ; i < res.size() ; ++ i)
	{
		BOOST_CHECK(res[i][0] == result[i][0]);
		BOOST_CHECK(res[i][1] == result[i][1]);
	}
}


BOOST_AUTO_TEST_SUITE_END()

