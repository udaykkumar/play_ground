#include <23_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_23_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	daily_interview::stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(2);
	s.push(5);
	s.push(8);
	s.push(4);

	BOOST_CHECK( s.max() == 8);
}


BOOST_AUTO_TEST_CASE( Case_2 )
{
	daily_interview::stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(2);
	s.push(5);
	s.push(8);
	s.push(4);
	s.pop();
	s.pop();
	s.pop();
	BOOST_CHECK( s.max() == 3 );	
}


BOOST_AUTO_TEST_CASE( Case_3 )
{
	daily_interview::stack s;
	for( int i = 0 ; i < 10000; i ++ )
	{
		s.push(i);
		BOOST_CHECK(s.max() == i );
	}

	for( int i = 0 ; i < 10000; i ++ )
	{
		BOOST_CHECK(s.max() == (10000-i-1) );
		s.pop();
	}
}



BOOST_AUTO_TEST_CASE( Case_4 )
{
	daily_interview::stack s;
	s.push(1);
	s.push(6);	
	s.push(7);
	s.push(110);
	s.push(123);
	s.push(100);
	BOOST_CHECK( s.max() == 123 );
	s.pop();
	BOOST_CHECK( s.max() == 123 );
	s.pop();
	BOOST_CHECK( s.max() == 110 );
	s.pop();
	BOOST_CHECK( s.max() == 7 );

}



BOOST_AUTO_TEST_SUITE_END()

