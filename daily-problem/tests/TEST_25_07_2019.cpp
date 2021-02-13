#include <25_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_25_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<size_t> v = {3, 5, 12, 5, 13};
	BOOST_CHECK( daily_interview::is_there_a_pythagorean_triplet(v) == true );
}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::vector<size_t> v ;
	for( size_t i = 1; i < 100; i ++ )
		v.push_back(i);

	BOOST_CHECK( daily_interview::is_there_a_pythagorean_triplet(v) == true );
}


BOOST_AUTO_TEST_CASE( Case_3 )
{
	std::vector<size_t> v ;
	for( size_t i = 1; i < 10000; i ++ )
		v.push_back(23);
	
	v[997] = 293;
	v[998] = 285;
	v[996] = 68;
	
	BOOST_CHECK( daily_interview::is_there_a_pythagorean_triplet(v) == true );
}


BOOST_AUTO_TEST_CASE( Case_4 )
{
	std::vector<size_t> v ;
	for( size_t i = 1; i < 10000; i ++ )
		v.push_back(1);
	
	BOOST_CHECK( daily_interview::is_there_a_pythagorean_triplet(v) == false );
}

BOOST_AUTO_TEST_SUITE_END()

